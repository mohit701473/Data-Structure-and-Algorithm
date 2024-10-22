https://leetcode.com/problems/longest-palindromic-substring/


class Solution {
public:
    vector<int> manchers(string &s) {
        int n = s.size();
        int c = 0, r = 0;
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            if (i <= r) {
                int mirr = c - (i - c);
                lps[i] = min(lps[mirr], r-i);
            }

            while(s[i + lps[i] + 1] == s[i - lps[i] - 1]) {
                lps[i]++;
            }

            if (i + lps[i] > r) {
                c = i;
                r = i + lps[i];
            }
        }

        return lps;
    }

    // @#c#b#bd#$
    // @#b#a#b#a#d#$

    string longestPalindrome(string s) {
        string ust = "@#";
        for (auto &ch: s) {
            ust.push_back(ch);
            ust.push_back('#');
        }
        ust.push_back('$');

        vector<int> lps = manchers(ust);
        int maxLen = -1, idx = -1;
        for (int i = 0; i < lps.size(); i++) {
            if (lps[i] > maxLen) {
                maxLen = lps[i];
                idx = i;
            }
        }

        int startIdx = (idx - maxLen + 1);
        int idxInOrgStr = (startIdx - 2) / 2;
        return s.substr(idxInOrgStr, maxLen);
    }
};




class Solution {
public:
    vector<int> manchers(string &s) {
        int n = s.size();
        int c = 0, r = 0;
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            if (i < r) {
                int mirr = c - (i - c);
                lps[i] = min(lps[mirr], r-i);
            }

            while(s[i + lps[i] + 1] == s[i - lps[i] - 1]) {
                lps[i]++;
            }

            if (i + lps[i] > r) {
                c = i;
                r = i + lps[i];
            }
        }

        return lps;
    }

    // @#c#b#bd#$
    // @#b#a#b#a#d#$

    string longestPalindrome(string s) {
        string ust = "@#";
        for (auto &ch: s) {
            ust.push_back(ch);
            ust.push_back('#');
        }
        ust.push_back('$');
        // cout << ust << "\n";

        vector<int> lps = manchers(ust);
        int maxLen = -1, idx = -1;
        for (int i = 0; i < lps.size(); i++) {
            if (lps[i] > maxLen) {
                maxLen = lps[i];
                idx = i;
            }
        }

        // cout << "idx: " << idx << " maxLen: " << maxLen << "\n";

        string left = "", right = "";
        int l = idx - maxLen, r = idx + 1, cnt = 0;
        if (maxLen % 2 != 0) {
            right.push_back(ust[idx]);
        }

        while (cnt < maxLen) {
            // cout << "l: " << l << " -> " << ust[l] << "\n";
            // cout << "r: " << r << " -> " << ust[r] << "\n\n";
            if (ust[l] != '#') left.push_back(ust[l]);
            if (ust[r] != '#') right.push_back(ust[r]);
            l++, r++, cnt++;
        }

        return left + right;
    }
};






class Solution {
public:
    vector<int> manchers(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            while(s[i + lps[i] + 1] == s[i - lps[i] - 1]) {
                lps[i]++;
            }
        }

        return lps;
    }

    // @#c#b#bd#$
    // @#b#a#b#a#d#$

    string longestPalindrome(string s) {
        string ust = "@#";
        for (auto &ch: s) {
            ust.push_back(ch);
            ust.push_back('#');
        }
        ust.push_back('$');
        // cout << ust << "\n";

        vector<int> lps = manchers(ust);
        int maxLen = -1, idx = -1;
        for (int i = 0; i < lps.size(); i++) {
            if (lps[i] > maxLen) {
                maxLen = lps[i];
                idx = i;
            }
        }

        // cout << "idx: " << idx << " maxLen: " << maxLen << "\n";

        string left = "", right = "";
        int l = idx - maxLen, r = idx + 1, cnt = 0;
        if (maxLen % 2 != 0) {
            right.push_back(ust[idx]);
        }

        while (cnt < maxLen) {
            // cout << "l: " << l << " -> " << ust[l] << "\n";
            // cout << "r: " << r << " -> " << ust[r] << "\n\n";
            if (ust[l] != '#') left.push_back(ust[l]);
            if (ust[r] != '#') right.push_back(ust[r]);
            l++, r++, cnt++;
        }

        return left + right;
    }
};



// DP
// Recursive + Memoization
class Solution {
public:
    int dp[1001][1001];

    int isPalindrome(int i, int j, string &s) {
        if (i >= j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = isPalindrome(i+1, j-1, s);
        
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = -1, idx = -1;

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    if ((j - i + 1) > maxLen) {
                        maxLen = j - i + 1;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx, maxLen);
    }
};


//Approach 3 - Using Bottom Up (Elaborated for simplicity) - My favourite BluePrint for solving palindromic DP problems
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxL  = 0;
        int index = 0;
        
        vector<vector<bool>> t(n, vector<bool>(n));
        //t[i][j] = lps in s[i...j]
        
        maxL = 1; //every letter is a substring and pallindrome as well
        for(int i = 0; i<n; i++) {
            t[i][i] = true;
            /*
                s[0..0] = pallindrome
                s[1..1] = pallindrome
                s[2..2] = pallindrome
                .
                .
                .
            */
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if(j-i+1 > maxL) {
                        maxL = j-i+1;
                        index = i;
                    }
                } else {
                    t[i][j] = false;
                }
                
            }    
        }
        
        
        return s.substr(index, maxL);
    }
};