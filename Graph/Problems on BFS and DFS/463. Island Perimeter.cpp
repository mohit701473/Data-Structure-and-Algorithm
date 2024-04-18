// LeetCode -> 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/description/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q ;
        int n = grid.size(), m = grid[0].size() ;

        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    q.push({i, j}) ;
                    grid[i][j] = 2 ;
                    break ;
                }
            }
            if(!q.empty())
                break ;
        }

        int ans = 0 ;
        int dRow[] = {-1, 1, 0, 0} ;
        int dCol[] = {0, 0, -1, 1} ;

        while(!q.empty()){
            int i = q.front().first ;
            int j = q.front().second ;
            q.pop() ;

            for(int k=0 ; k<4 ; k++){
                int nb_i = i + dRow[k] ;
                int nb_j = j + dCol[k] ;

                if(nb_i >= 0 && nb_i <n && nb_j >= 0&& nb_j < m){
                    if(grid[nb_i][nb_j] == 1){
                        q.push({nb_i, nb_j}) ;
                        grid[nb_i][nb_j] = 2 ;
                    }
                    else if(grid[nb_i][nb_j] != 2){
                        ans++ ;
                    }
                }
                else{
                    ans++ ;
                }

            }
        }

        return ans ;
    }
};







class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q ;
        int n = grid.size(), m = grid[0].size() ;
        int peri = 0 ;
        int dRow[] = {-1, 1, 0, 0} ;
        int dCol[] = {0, 0, -1, 1} ;

        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                
                if(grid[i][j]){
                    peri += 4 ;
                    for(int k=0 ; k<4 ; k++){
                        int nb_i = i + dRow[k] ;
                        int nb_j = j + dCol[k] ;
                        if(nb_i >= 0 && nb_i <n && nb_j >= 0&& nb_j < m && grid[nb_i][nb_j]){
                            peri-- ;
                        }
                    }
                }
            }
        }

        return peri ;
    }
};