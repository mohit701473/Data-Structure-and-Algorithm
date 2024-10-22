https://leetcode.com/problems/shortest-palindrome/


class Solution {
public:
    int computeLPS(string &s) {
        int n = s.size();
        vector<int> LPS(n+1, 0);

        int i = 1, len = 0;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        
        return LPS[n-1];
    }

    string shortestPalindrome(string s) {
        int n = s.size(), maxi = 0, maxIdx = 0;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string us = s + "#" + rev;
        int maxLenPalindrome = computeLPS(us);
        cout << maxLenPalindrome << "\n";
        string remStr = s.substr(maxLenPalindrome, n-maxLenPalindrome);
        cout << remStr << "\n";
        reverse(remStr.begin(), remStr.end());

        return remStr + s;
    }
};



class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        for (int i = 0; i < n; i++) {
            if (memcmp(s.c_str(), rev.c_str() + i, n - i) == 0)
                return rev.substr(0, i) + s;
        }

        return rev + s;
    }
};




// class Solution {
// public:
//     bool isPalindrome(string &s, int l, int r) {
//         while (l < r) {
//             if (s[l] != s[r])
//                 return false;
//             l++, r--;
//         }

//         return true;
//     }
//     string shortestPalindrome(string s) {
//         int n = s.size();
//         int i = 0, j = n-1;

//         while (i < j) {
//             if (isPalindrome(s, i, j)) {
//                 break;
//             }
//             j--;
//         }

//         j++;
//         string str = s.substr(j, (n - j));
//         reverse(str.begin(), str.end());
//         return str + s;
//     }
// };