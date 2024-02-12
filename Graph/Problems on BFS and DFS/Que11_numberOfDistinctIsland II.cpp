// GFG -> Number of Distinct Islands
https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1



// Approch -> DFS
// T.C. = O(n * m * 4) + O(n * m)
// S.C. = O(2 * n * m)
class Solution {
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int baseI, int baseJ){
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        vis[i][j] = 1 ;
        vec.push_back({i-baseI, j-baseJ}) ;
        
        int delRow[] = {-1, 0, 1, 0} ;
        int delCol[] = {0, -1, 0, 1} ;
        for(int k=0 ; k<4 ; k++){
            int nbRow = i + delRow[k] ;
            int nbCol = j + delCol[k] ;

            if(nbRow >= 0 && nbRow < n && nbCol >= 0 && nbCol < m){
                if(!vis[nbRow][nbCol] && grid[nbRow][nbCol] == 1){
                    dfs(nbRow, nbCol, grid, vis, vec, baseI, baseJ) ;
                }
            }   
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int> (m, 0)) ;
        set<vector<pair<int, int>>> st ;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec ;
                    dfs(i, j, grid, vis, vec, i, j) ;
                    st.insert(vec) ;
                }
            }
        }
        
        return st.size() ;
    }
};