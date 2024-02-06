// LeetCode -> 200. Number of Islands
https://leetcode.com/problems/number-of-islands/description/



// Approch -> BFS or DFS
// T.C. = O(N^2)
// S.C. = O(N^2)
class Solution {

    void bfs(int st_i, int st_j, vector<vector<char>>& grid, vector<vector<int>> &vis){
        int rows = grid.size(), cols = grid[0].size() ;
        queue<pair<int, int>> q ;
        q.push({st_i, st_j}) ;
        vis[st_i][st_j] = 1 ;

        while(!q.empty()){
            pair<int, int> node = q.front() ;
            int i = node.first, j = node.second ;
            q.pop() ;

            // insert the neighbors of node which are lands and not visited into queue
            // UP
            if(i-1 >= 0 && (!vis[i-1][j] && grid[i][j] == '1')){
                q.push({i-1, j}) ; 
                vis[i-1][j] = 1 ;
            }

            // Down
            if(i+1 < rows && (!vis[i+1][j] && grid[i][j] == '1')){
                q.push({i+1, j}) ; 
                vis[i+1][j] = 1 ;
            }

            // Left
            if(j-1 >= 0 && (!vis[i][j-1] && grid[i][j] == '1')){
                q.push({i, j-1}) ; 
                vis[i][j-1] = 1 ;
            }

            // Right
            if(j+1 < cols && (!vis[i][j+1] && grid[i][j] == '1')){
                q.push({i, j+1}) ; 
                vis[i][j+1] = 1 ;
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int island_cnt = 0, rows = grid.size(), cols = grid[0].size() ;
        vector<vector<int>> vis(rows, vector<int> (cols, 0)) ;
        
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<cols ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    // {i, j} is a starting point
                    island_cnt++ ;
                    bfs(i, j, grid, vis) ;
                }
            }
        }

        return island_cnt ;
    }
};