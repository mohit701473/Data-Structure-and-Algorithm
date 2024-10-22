https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/


class Solution {
public:
    vector<int> computeLPS(string &s) {
        int n = s.size(), i = 1, len = 0;
        vector<int> LPS(n, 0);

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = LPS[len-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        string us = needle + "#" + haystack; // us = updated string
        vector<int> LPS = computeLPS(us);

        for (int i = m+1; i < (m + n + 1); i++) {
            if (LPS[i] == m)
                return i - (m+1) - (m-1);
                // return i - (2 * m);
        }

        return -1;
    }
};

// Approch 1 -> Brute Force
// T.C. = O(n*m)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size(), m = needle.size();
//         int i = 0;

//         while (i < n) {
//             int j = 0, temp_i = i;
//             while (j < m && temp_i < n && haystack[temp_i] == needle[j]) {
//                 temp_i++, j++;
//             }

//             if (j >= m)
//                 return i;
//             i++;
//         }

//         return -1;
//     }
// };