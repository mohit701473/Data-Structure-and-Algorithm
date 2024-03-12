// LeetCode -> 1091. Shortest Path in Binary Matrix
https://leetcode.com/problems/shortest-path-in-binary-matrix/description/


// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1 ;

        int n = grid.size() ;
        queue<pair<int, pair<int, int>>> q ;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX)) ;

        dist[0][0] = 1 ;
        q.push({1, {0, 0}}) ;

        while(!q.empty()){
            int dis = q.front().first ;
            int x = q.front().second.first ;
            int y = q.front().second.second ;
            q.pop() ;

            int nb_x[] = {0, -1, 1} ;
            int nb_y[] = {0, -1, 1} ;
            for(auto i: nb_x){
                for(auto j: nb_y){
                    int adj_x = x+i ;
                    int adj_y = y+j ;
                    if(i == 0 && j == 0) continue ;

                    if(adj_x >= 0 && adj_x < n && adj_y >= 0 && adj_y < n){
                        if(grid[adj_x][adj_y] == 0 && dis + 1 < dist[adj_x][adj_y]){
                            dist[adj_x][adj_y] = dis + 1 ;
                            q.push({dist[adj_x][adj_y], {adj_x, adj_y}}) ;
                        }
                    }
                }
            }
        }

        return dist[n-1][n-1] != INT_MAX ? dist[n-1][n-1] : -1 ;
    }
};





// T.C. = O(E* log(V))
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1 ;

        int n = grid.size() ;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq ;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX)) ;

        dist[0][0] = 1 ;
        pq.push({1, {0, 0}}) ;

        while(!pq.empty()){
            int dis = pq.top().first ;
            int x = pq.top().second.first ;
            int y = pq.top().second.second ;
            pq.pop() ;

            int nb_x[] = {0, -1, 1} ;
            int nb_y[] = {0, -1, 1} ;
            for(auto i: nb_x){
                for(auto j: nb_y){
                    int adj_x = x+i ;
                    int adj_y = y+j ;
                    if(i == 0 && j == 0) continue ;

                    if(adj_x >= 0 && adj_x < n && adj_y >= 0 && adj_y < n){
                        if(grid[adj_x][adj_y] == 0 && dis + 1 < dist[adj_x][adj_y]){
                            dist[adj_x][adj_y] = dis + 1 ;
                            pq.push({dist[adj_x][adj_y], {adj_x, adj_y}}) ;
                        }
                    }
                }
            }
        }

        return dist[n-1][n-1] != INT_MAX ? dist[n-1][n-1] : -1 ;
    }
};