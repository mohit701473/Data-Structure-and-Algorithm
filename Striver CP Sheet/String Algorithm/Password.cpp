/*
 * Approch 1 -> Simple Z-Algoritm
 * 
 * Que. -> Why Simple Z-Algo is not working?
 * Sol. -> In simple Z-Algo the Z-Function say that find the
 * longest substring which is also a proper prefix for every
 * index i.
 * Now according the simple Z-Algo if we look the test case
 * Input = fixprefixsuffix
 * Output = fix
 * Answer = fix
 * then we can think like that if any substring match with
 * propper prefix then suppose the length of substring is 3
 * so in that case if from end of the string i.e. proper
 * suffix is also match with 3 length PP then u can say that 
 * this is a valid answer for u
 * 
 * But the code fails when the test case is like
 * Input = qwertyqwertyqwertyqw
 * Output = Just a legend
 * Answer = qwerty
 * 
 * This is bcz for z[6] = 14 and when u check for the
 * z[i] == z[n - z[i]] && i != (n - z[i]) conditon then 
 * ur code not work properly
 * 
 * So we need to some changes in simple Z-Algo
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int n;
int z[N] = {0};

void zfunction(string &s) {
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i-l], r-i+1);
        }

        while (s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void z_algo(string &s) {
    zfunction(s);

    int idx = -1, maxlen = 0;
    for (int i = 1; i < n; i++) {
        cout << "i: " << i << " z[i]: " << z[i] << "\n";
        if (z[i] == z[n - z[i]] && i != (n - z[i]) && maxlen < z[i]) {
            maxlen = z[i];
            idx = i;
        }
    }
    cout  << "idx: " << idx << " z[idx]: " << z[idx] << "\n";
    if (maxlen != 0)
        cout << s.substr(idx, maxlen) << "\n";
    else cout << "Just a legend" << "\n";
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    z_algo(s);
}

int main() {
    solve();
    return 0;
}



