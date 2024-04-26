// LeetCode -> 2370. Longest Ideal Subsequence


// DP -> Recursion + Memoization
// T.C. = o(27 * n)
// S.C. = O(27 * n) + O(n)
class Solution {
public:

    int solve(int idx, char last, string& s, int k, vector<vector<int>>& dp){
        if(idx >= s.size())
            return 0 ;

        int pick = 0, notpick = 0;
        int prev_ch = last == '$' ? 26 : last - 'a';

        if(dp[idx][prev_ch] != -1)
            return dp[idx][prev_ch];

        if(last == '$' || abs(last - s[idx]) <= k){ // abs((last - 'a') - (s[idx] - 'a')
            pick = solve(idx+1, s[idx], s, k, dp) + 1;
        }

        notpick = solve(idx+1, last, s, k, dp);

        return dp[idx][prev_ch] = max(pick, notpick);

    }

    int longestIdealString(string s, int k) {
        // cout << abs(s[1] -s[0]);
        vector<vector<int>> dp(s.size(), vector<int>(27, -1));
        return solve(0, '$', s, k, dp);
    }
};



//DP -> Tabulation
class Solution {
public:

    // int solve(int idx, char last, string& s, int k, vector<vector<int>>& dp){
    //     if(idx >= s.size())
    //         return 0 ;

    //     int pick = 0, notpick = 0;
    //     int prev_ch = last == '$' ? 26 : last - 'a';

    //     if(dp[idx][prev_ch] != -1)
    //         return dp[idx][prev_ch];

    //     if(last == '$' || abs(last - s[idx]) <= k){ // abs((last - 'a') - (s[idx] - 'a')
    //         pick = solve(idx+1, s[idx], s, k, dp) + 1;
    //     }

    //     notpick = solve(idx+1, last, s, k, dp);

    //     return dp[idx][prev_ch] = max(pick, notpick);

    // }

    int longestIdealString(string s, int k) {
        //vector<vector<int>> dp(s.size(), vector<int>(27, -1));
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(27, 0));

        // for(int idx = n-1; idx >= 0; idx--){
        //     dp[idx][26] = 1;
        // }


        for(int idx = n-1; idx >= 0; idx--){
            for(int last_ch = 26; last_ch >= 0; last_ch--){
                int pick = 0, notpick = 0;
                if(last_ch == 26 || abs(last_ch - (s[idx] - 'a')) <= k){
                    pick = dp[idx+1][(s[idx] - 'a')] + 1;
                }

                notpick = dp[idx+1][last_ch];

                dp[idx][last_ch] = max(pick, notpick);
            }
        }

        return dp[0][26];

        //return solve(0, '$', s, k, dp);
    }
};