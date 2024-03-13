// LeetCode -> 1631. Path With Minimum Effort
https://leetcode.com/problems/path-with-minimum-effort/description/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size() ;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq ;
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX)) ;
        vector<int> dr = {0, -1, 0, 1} ;
        vector<int> dc = {-1, 0, 1, 0} ;

        dist[0][0] = 0 ;
        pq.push({0, {0, 0}}) ;

        while(!pq.empty()){
            int diff = pq.top().first ;
            int x = pq.top().second.first ;
            int y = pq.top().second.second ;
            pq.pop() ;

            if(x == m-1 && y == n-1){
                return diff ;
            }

            for(int i=0 ; i<4 ; i++){
                int newx = x + dr[i] ;
                int newy = y + dc[i] ;

                if(newx >= 0 && newx < m  && newy >=0 && newy < n){
                    int newEffort = max(abs(heights[x][y] - heights[newx][newy]), diff) ;
                    if(newEffort < dist[newx][newy]){
                        dist[newx][newy] = newEffort ;
                        pq.push({dist[newx][newy], {newx, newy}}) ;
                    }
                }
            }
        }

        return 0 ;
    }
};