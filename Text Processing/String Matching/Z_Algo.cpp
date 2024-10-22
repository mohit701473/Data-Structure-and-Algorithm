https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/


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

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        string us = needle + "#" + haystack;
        vector<int> z = zfunction(us);

        for (int i = m+1; i < z.size(); i++) {
            if (z[i] == m)
                return i - m - 1;
        }

        return -1;
    }
};
