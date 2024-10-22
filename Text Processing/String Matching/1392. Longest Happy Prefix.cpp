https://leetcode.com/problems/longest-happy-prefix/description/

// Approch -> 1: KMP Algorithm
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    vector<int> ComputeLPS(string &s) {
        int n = s.size();
        vector<int> LPS(n, 0);
        int i = 1, len = 0;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len =  LPS[len-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS;
    }

    string longestPrefix(string s) {
        int n = s.size();
        vector<int> LPS = ComputeLPS(s);
        int len = LPS[n-1];
        return s.substr(0, len);
    }
};


// Approch -> 2: Z-Alorithm
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    vector<int> zfunction(string &s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n, 0);

        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }

            while (s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }

    string longestPrefix(string s) {
        int n = s.size();
        vector<int> z_arr = zfunction(s);

        int idx = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (z_arr[i] ==  n - i) {
                return s.substr(i, n-i);
            }
        }

        return "";
    }
};


// Approch -> 2: Rabin Karp Rolling Hash
// T.C. = O(n)
// S.C. = O(1)
#define ll long long int
class Solution {
public:
    string longestPrefix(string s) {
        ll n = s.size();
        ll mod = 1e9 + 7;
        ll p = 31, pow = 1;
        ll ph = 0, sh = 0, pph = 0, psh = 0;
        // ph = prefix hash
        // sh = suffix hash
        // pph = previous prefix hash
        // psh = previous suffix hash

        ll len = 0;
        for (ll i = 0; i < (n - 1); i++) {
            ph = (pph * p + (s[i] - 'a' + 1)) % mod;
            sh = (psh + (s[n-i-1] - 'a' + 1) * pow) % mod;

            if (ph == sh)
                len = i + 1;

            pph = ph;
            psh = sh;
            pow = (pow * p) % mod;
        }

        return s.substr(0, len);
    }
};