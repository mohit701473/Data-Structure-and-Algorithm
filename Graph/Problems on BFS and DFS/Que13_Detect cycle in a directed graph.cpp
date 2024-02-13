// GFG -> Detect cycle in a directed graph
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// Approch -> DFS
// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
class Solution {
        
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1 ;
        pathVis[node] = 1 ;
        
        for(auto nb: adj[node]){
            if(!vis[nb]){
                if(dfs(nb, adj, vis, pathVis)){
                    return true ;
                }
            }else{
                if(pathVis[nb]){
                    return true ;
                }
            }
        }
        
        pathVis[node] = 0 ;
        return false ;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), pathVis(V, 0) ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)){
                    return true ;
                }
            }
        }
        
        return false ;
    }
};