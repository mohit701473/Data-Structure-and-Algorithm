// Good problem to pratice Rabin karp Algo
// Here when u use simple Rabin Karp Algo then u get Hash Collision
// To avoid Hash collision u can use two prime number i.e. generate
// Hash value of string using both the prime number and store and when 
// u get the duplicate string then both hashes of the prime number should
// be same

// Other thing u can use mod = 1e16 + 7; this remove ur collision

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e16 + 7;
ll powers[1501];
ll p = 31;

void compuetPowers(ll n) {
    powers[0] = 1;
    for (ll i = 1; i < n; i++) {
        powers[i] = (powers[i - 1] * p) % mod;
    }
}


void solve() {
    string s, bad;
    cin >> s >> bad;

    ll k, n;
    cin >> k;

    n = s.size();
    compuetPowers(n);
    unordered_set<ll> st;

    for (ll i = 0; i < n; i++) {
        ll badCnt = 0;
        ll hash = 0;
        for (ll j = i; j < n; j++) {
            char ch = s[j];
            badCnt += (bad[ch - 'a'] == '0') ? 1 : 0;

            if (badCnt > k)
                break;

            hash = (hash + ((ch - 'a' + 1) * powers[j - i])) % mod;
            st.insert(hash); 
        }
    }

    cout << st.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);  // Faster I/O
    cin.tie(nullptr);  // Disable I/O synchronization
    solve();
    return 0;
}