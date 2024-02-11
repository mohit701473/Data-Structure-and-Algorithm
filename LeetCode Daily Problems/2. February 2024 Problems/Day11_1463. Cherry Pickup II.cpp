https://leetcode.com/problems/cherry-pickup-ii/description/

// Approch -> DP Memoization
// T.C. = O(n * m * m * 9)
// S.C. = O(n * m * m) + O(n)
class Solution {

    int solve(int i, int j1, int j2, vector<vector<int>>& grid){
        // Base cases
        // base case 1 -> Out of bound base case
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return -1e8 ;
        }
        // base case 2 -> Destination base case
        if(i == n-1){
            if(j1 == j2) return grid[i][j1] ;
            return grid[i][j1] + grid[i][j2] ;
        }

        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2] ;
        }

        // Explore all possibilites ;
        int maxi = -1e8 ;
        for(int dj1 = -1 ; dj1 <= +1 ; dj1++){
            for(int dj2 = -1 ; dj2 <= +1 ; dj2++){
                int val = 0 ;
                if(j1 == j2){
                    val = grid[i][j1] ;
                }
                else{
                    val = grid[i][j1] + grid[i][j2] ;
                }

                val += solve(i+1, j1+dj1, j2+dj2, grid) ;
                maxi = max(maxi, val) ;
            }
        }

        return dp[i][j1][j2] =  maxi ;
    }

public:
    int n, m ;
    vector<vector<vector<int>>> dp ;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size() ;
        dp = vector<vector<vector<int>>> (n, vector<vector<int>> (m, vector<int> (m, -1))) ;
        return solve(0, 0, m-1, grid) ;
    }
};



// Approch -> DP Memoization
// T.C. = O(n * m * m * 9)
// S.C. = O(n * m * m)
class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1))) ;

        // write the base cases
        for(int j1 = 0 ; j1 < m ; j1++){
            for(int j2 = 0 ; j2 < m ; j2++){
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1] ;
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2] ;
            }
        }


        // write for loop
        for(int i = n-2 ; i>=0 ; i--){
            for(int j1 = 0 ; j1 < m ; j1++){
                for(int j2 = 0 ; j2 < m ; j2 ++){
                    // copy the recurance
                    // Explore all possibilites ;
                    int maxi = -1e8 ;
                    for(int dj1 = -1 ; dj1 <= +1 ; dj1++){
                        for(int dj2 = -1 ; dj2 <= +1 ; dj2++){
                            int val = 0 ;
                            if(j1 == j2){
                                val = grid[i][j1] ;
                            }
                            else{
                                val = grid[i][j1] + grid[i][j2] ;
                            }
                            
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m){
                                val += dp[i+1][j1+dj1][j2+dj2] ; // solve(i+1, j1+dj1, j2+dj2, grid) ;
                                maxi = max(maxi, val) ;
                            }
                        }
                    }
                    dp[i][j1][j2] =  maxi ;
                }
            }
        }

        return dp[0][0][m-1] ;
    }
};