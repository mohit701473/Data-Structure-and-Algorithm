// LeetCode -> 1289. Minimum Falling Path Sum II



// Reciursion + Memoization
class Solution {
public:

    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row >= grid.size())
            return 0;

        if(col != -1 && dp[row][col] != -1)
            return dp[row][col];

        int ans = INT_MAX;
        for(int i = 0; i < grid.size(); i++){
            if(i == col) continue;
            int sum = solve(row+1, i, grid, dp) + grid[row][i];
            ans = min(ans, sum);
        }

        if(col == -1){
            return ans;
        }

        return dp[row][col] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, -1, grid, dp);
    }
};



class Solution {
public:

    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row >= grid.size())
            return 0;

        if(dp[row][col] != -1)
            return dp[row][col];

        int ans = INT_MAX;
        for(int i = 0; i < grid.size(); i++){
            if(i == col) continue;
            int sum = solve(row+1, i, grid, dp) + grid[row][i];
            ans = min(ans, sum);
        }

        return dp[row][col] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            int sum = solve(1, i, grid, dp);
            dp[0][i] = (sum != INT_MAX ? sum : 0) + grid[0][i];
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
};


