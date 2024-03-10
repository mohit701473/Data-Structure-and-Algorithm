// GFG -> Shortest path in Undirected Graph having unit distance
https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1


// Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
// Expected Space Complexity: O(N)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N] ;
        vector<int> dist(N, INT_MAX) ;
        queue<pair<int, int>> q ; 
        
        // convert the edges into a adj list
        for(int i=0 ; i<M ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        
        q.push({src, 0}) ;
        dist[src] = 0 ;
        
        while(!q.empty()){
            int node = q.front().first ;
            int d = q.front().second ;
            q.pop() ;
            
            for(auto nb: adj[node]){
                if(d + 1 < dist[nb]){
                    dist[nb] = d + 1 ;
                    q.push({nb, dist[nb]}) ;
                }
            }
        }
        
        for(int i=0 ; i<N ; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1 ;
            }
        }
        
        return dist ;
    }
};