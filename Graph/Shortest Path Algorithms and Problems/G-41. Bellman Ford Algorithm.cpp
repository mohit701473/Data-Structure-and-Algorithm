// GFG -> Distance from the Source (Bellman-Ford Algorithm)
https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


// Expected Time Complexity: O(V*E).
// Expected Auxiliary Space: O(V).
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, int(1e8)) ;
        dist[S] = 0 ;
        
        // relax the edges n-1 time or V-1 time 
        for(int i=1 ; i<V ; i++){
            for(auto it: edges){
                int u = it[0] ;
                int v = it[1] ;
                int wt = it[2] ;
                
                if(dist[u] != (int)(1e8) && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt ;
                }
            }
        }
        
        // check for n-th time relax
        for(auto it: edges){
            int u = it[0] ;
            int v = it[1] ;
            int wt = it[2] ;
                
            if(dist[u] != (int)(1e8) && dist[u] + wt < dist[v]){
                return {-1} ;
            }
        }
        
        return dist ;
    }
};