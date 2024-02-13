// GFG -> Eventual Safe States
https://www.geeksforgeeks.org/problems/eventual-safe-states/1


// Approch -> DFS
// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)
class Solution {
    
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1 ;
        pathVis[node] = 1 ;
        
        for(auto nb: adj[node]){
            if(!vis[nb]){
                if(dfs(nb, adj, vis, pathVis, check)){
                    return true ;
                }
            }else{
                if(pathVis[nb]){
                    return true ;
                }
            }
        }
        
        check[node] = 1 ;
        pathVis[node] = 0 ;
        return false ;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), pathVis(V, 0), check(V, 0), safeNodes ;
        
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis, check) ;
            }
        }
        
        
        for(int i=0 ; i<V ; i++){
            if(check[i]){
                safeNodes.push_back(i) ;
            }
        }
        
        return safeNodes ;
    }
};