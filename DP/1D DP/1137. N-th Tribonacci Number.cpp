// LeetCode -> 1137. N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/description/


// Recursion + Memoziation
class Solution {
public:

    int f(int n,vector<int> &dp){
        if(n <= 2){
            return n == 0 ? 0 : 1;
        }

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};



// Tabulation
class Solution {
public:

    int tribonacci(int n) {
        if(n <= 2){
            return n == 0 ? 0 : 1;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};



// Space Optimization
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;

        int first = 0, second = 1, third = 1;
        int ans = 0;

        for(int i = 3; i <= n; i++){
            ans = first + second + third;
            first = second;
            second = third;
            third = ans;
        }
        
        return ans ;
    }
};