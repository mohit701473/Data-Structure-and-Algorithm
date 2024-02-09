// LeetCode -> 130. Surrounded Regions
https://leetcode.com/problems/surrounded-regions/


// Approch -> BFS
// T.C. = O(n * m)
// S.C. = O(n * m)
class Solution {

    void bfsIsSurroundedRegions(int st_i, int st_j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size(), m = board[0].size() ;
        queue<pair<int, int>> q ;
        q.push({st_i, st_j}) ;
        vis[st_i][st_j] = 1 ;

        int nbRow[] = {-1, 0, 1, 0} ;
        int nbCol[] = {0, -1, 0, 1} ;
        while(!q.empty()){
            int i = q.front().first ;
            int j = q.front().second ;
            q.pop() ;

            for(int k=0 ; k<4 ; k++){
                int row = i + nbRow[k] ;
                int col = j + nbCol[k] ;

                if(row >= 0 && row < n && col >= 0 && col < m){
                    if(!vis[row][col] && board[row][col] == 'O'){
                        q.push({row, col}) ;
                        vis[row][col] = 1 ;
                    }
                }   
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size() ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;

        // 1st row
        for(int col = 0 ; col < m ; col++){
            if(board[0][col] == 'O' && !vis[0][col]){
                bfsIsSurroundedRegions(0, col, board, vis) ;
            }
        }

        // last row
        for(int col = 0 ; col < m ; col++){
            if(board[n-1][col] == 'O' && !vis[n-1][col]){
                bfsIsSurroundedRegions(n-1, col, board, vis) ;
            }
        }

        // 1st col
        for(int row = 0 ; row < n ; row++){
            if(board[row][0] == 'O' && !vis[row][0]){
                bfsIsSurroundedRegions(row, 0, board, vis) ;
            }
        }

        // last col
        for(int row = 0 ; row < n ; row++){
            if(board[row][m-1] == 'O' && !vis[row][m-1]){
                bfsIsSurroundedRegions(row, m-1, board, vis) ;
            }
        }

        // flipped
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j]){
                    board[i][j] = 'X' ;
                }
            }
        }

    }
};