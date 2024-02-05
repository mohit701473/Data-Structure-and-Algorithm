// GFG -> DFS of graph
https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// T.C. = O(N + 2E)
// S.C. = O(E)
class Solution {
    
    void dfsTraversal(int node, vector<int> adj[]){
        vis[node] = 1 ;
        dfs.push_back(node) ;
        
        for(auto nb: adj[node]){
            if(!vis[nb]){
                dfsTraversal(nb, adj) ;
            }
        }
    }
    
  public:
  
    vector<int> dfs, vis ;
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vis = vector<int> (V, 0) ;
        dfsTraversal(0, adj) ;
        return dfs ;
    }
};