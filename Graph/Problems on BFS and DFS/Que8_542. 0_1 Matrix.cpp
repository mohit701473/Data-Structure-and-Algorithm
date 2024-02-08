// LeetCode -> 542. 01 Matrix
https://leetcode.com/problems/01-matrix/description/


/*
Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M) + O(N x M) ~ O(N x M)

O(N x M) for the visited array, distance matrix, and queue space takes up N x M locations at max. 
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size() ;
        vector<vector<int>> vis(n, vector<int> (m, 0)) ;

        queue<pair<pair<int, int>, int>> q ;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0}) ;
                    vis[i][j] = 1 ;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first ;
            int j = q.front().first.second ;
            int level = q.front().second ;
            // mat[i][j] = level ;
            q.pop() ;

            int nbRow[] = {-1, 0, 1, 0} ;
            int nbCol[] = {0, -1, 0, 1} ;
            for(int k = 0 ; k<4 ; k++){
                int row = i + nbRow[k] ;
                int col = j + nbCol[k] ;

                if(row >= 0 && row < n && col >= 0 && col < m){
                    if(!vis[row][col]){
                        mat[i][j] = level + 1 ;
                        q.push({{row, col}, level+1}) ;
                        vis[row][col] = 1 ;
                    }
                    
                }                
            }
        }

        return mat ;
    }
};