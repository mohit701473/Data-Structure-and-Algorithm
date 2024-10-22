https://leetcode.com/problems/longest-duplicate-substring/

// "baa"
// "zxcvdqkfawuytt"
// "zzzzzzz"
#define ll long long int

const ll N = 3e4 + 1;
ll mod = 1e16 + 7;
ll powers[N];
ll hashArr[N];
ll p = 31;
ll n;

class Solution {
public:
    void rabinKarp(string &s) {
        powers[0] = 1;
        hashArr[0] = 1ll * (s[0] - 'a' + 1);
        
        for (ll i = 1; i < n; i++) {
            ll ch = s[i] - 'a' + 1;
            powers[i] = (powers[i - 1] * p) % mod;
            hashArr[i] = (hashArr[i - 1] + (ch * powers[i])) % mod;
        }
    }

    bool isValidLen(string &s, ll len, int &idx) {
        unordered_set<ll> set;
        ll end = n-1, st = n - len;
        ll hash = (st == 0) ? hashArr[end] : ((hashArr[end] - hashArr[st - 1] + mod) % mod);
        set.insert(hash);
        // cout << "st: " << st << " hash: " << hash << "\n";

        while (st > 0) {
            hash = (hash - (((s[end] - 'a' + 1) * powers[n-1]) % mod) + mod) % mod;
            // cout << "hash1: " << hash << "\n";
            st--;
            hash = (hash * powers[1]) % mod;
            // cout << "hash2: " << hash << "\n";
            hash = (hash + ((s[st] - 'a' + 1) * powers[n-len]) % mod) % mod;
            end--;

            if (set.find(hash) != set.end()) {
                idx = st;
                cout << "idx: "<< idx << " len: " << len << "\n";
                return true;
            }

            // cout << "st: " << st << " hash: " << hash << "\n";
            set.insert(hash);
        }

        // cout << "len: " << len << " set size: " << set.size() << "\n";
        cout << "---------------------------------------------------\n\n";

        return false;
    }
    
    void print(string &s) {
        for (int i = n-1; i >= 0; i--) {
            cout << "i: " << i << " hashval: " << ((s[i] - 'a' + 1) * powers[n-1]) % mod << "\n";
        }
    }

    string longestDupSubstring(string s) {
        int idx = 0;
        int maxLen = 0;
        n = s.size();
        rabinKarp(s);

        ll l = 1, h = n-1;
        while (l <= h) {
            ll mid = (l + h) / 2;

            if (isValidLen(s, mid, idx)) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        // print(s);
        // cout << "h: " << h << "\n";
        // cout << "5: " << ((s[n-1] - 'a' + 1) * powers[n - 1]) % mod << "\n";

        return s.substr(idx, h);
    }
};