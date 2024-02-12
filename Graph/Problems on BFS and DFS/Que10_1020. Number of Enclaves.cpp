// LeetCode -> 1020. Number of Enclaves
https://leetcode.com/problems/number-of-enclaves/description/


// Approch -> DFS
// T.C. = O(n * m * 4) 
// S.C. = O(n * m) + O(max(n, m))
class Solution {

    void dfs(int i, int j, vector<vector<int>>& board, vector<vector<int>> &vis){

        int n = board.size(), m = board[0].size() ;
        vis[i][j] = 1 ;

        int rowIdx[] = {-1, 0, 1, 0} ;
        int colIdx[] = {0, -1, 0, 1} ;
        for(int k=0 ; k<4 ; k++){
            int nbRow = i + rowIdx[k] ;
            int nbCol = j + colIdx[k] ;

            if(nbRow >= 0 && nbRow < n && nbCol >= 0 && nbCol < m){
                if(!vis[nbRow][nbCol] && board[nbRow][nbCol] == 1){
                    dfs(nbRow, nbCol, board, vis) ;
                }
            }   
        }
    }

public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size() ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;

        // 1st row
        for(int col = 0 ; col < m ; col++){
            if(board[0][col] == 1 && !vis[0][col]){
                dfs(0, col, board, vis) ;
            }
        }

        // last row
        for(int col = 0 ; col < m ; col++){
            if(board[n-1][col] == 1 && !vis[n-1][col]){
                dfs(n-1, col, board, vis) ;
            }
        }

        // 1st col
        for(int row = 0 ; row < n ; row++){
            if(board[row][0] == 1 && !vis[row][0]){
                dfs(row, 0, board, vis) ;
            }
        }

        // last col
        for(int row = 0 ; row < n ; row++){
            if(board[row][m-1] == 1 && !vis[row][m-1]){
                dfs(row, m-1, board, vis) ;
            }
        }

        // now count number of lands cells that can't be reached
        int ans = 0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && board[i][j] == 1){
                    ++ans ;
                }
            }
        }

        return ans ;
    }
};