// GFG -> Shortest path in Directed Acyclic Graph
https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


// T.C. = O(V + E)
// S.C. = O(V)
class Solution {
    
    void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &topo){
        vis[node] = 1 ;
        
        for(auto nb: adj[node]){
            if(!vis[nb.first]){
                dfs(nb.first, adj, vis, topo) ;
            }
        }
        
        topo.push(node) ;
    }
    
    void topoSort(int V, vector<pair<int, int>> adj[], stack<int> &topo){
        vector<int> vis(V, 0) ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfs(i, adj, vis, topo) ;
            }
        }
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N] ;
        stack<int> topo ;
        vector<int> dis(N, INT_MAX) ;
         
        // firts convert the edge list into a adjecency list
        for(int i=0 ; i<M ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int w = edges[i][2] ;
            
            adj[u].push_back({v, w}) ;
        }
        
        // do a topo sort on the graph
        // T.C. = O(N + M) or O(V + E)
        topoSort(N, adj, topo) ;
        
        dis[0] = 0 ;
        // take the node out form the stack and relax the edges
        // T.C. = O(N + M) or O(V + E)
        while(!topo.empty()){
            int node = topo.top() ;
            topo.pop() ;
            
            for(auto nb: adj[node]){
                int v = nb.first ;
                int w = nb.second ;
                
                if(dis[node] != INT_MAX)
                    dis[v] = min(dis[v], (w + dis[node])) ;
            }
        }
        
        for(int i=0 ; i<N ; i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1 ;
            }
        }
        
        return dis ;
        
    }
};