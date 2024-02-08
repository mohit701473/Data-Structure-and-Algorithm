// GFG -> Detect cycle in an undirected graph
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


// Approch -> BFS
// T.C. = O(N + 2E) + O(N)
// S.C. = O(N) + O(N) + O(N)
class Solution {
    
    bool bfsDetectedCycle(int node, vector<int>& vis, vector<int> adj[]){
        
        queue<pair<int, int>> q ;
        q.push({node, -1}) ;
        vis[node] = 1 ;
        
        while(!q.empty()){
            int vertex = q.front().first ;
            int parent = q.front().second ;
            q.pop() ;
            
            for(auto nb: adj[vertex]){
                if(vis[nb] && nb != parent) 
                    return true ;
                    
                if(!vis[nb] && nb != parent){
                    q.push({nb, vertex}) ;
                    vis[nb] = 1 ;
                }
            }
        }
        
        return false ;
    }
    
  public:
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0) ;
        bool cycle = false ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                cycle = bfsDetectedCycle(i, vis, adj) ;
            }
            if(cycle) return true ;
        }
        
        return false ;
    }
};



// Approch -> DFS
// T.C. = O(N + 2E) + O(N)
// S.C. = O(N) + O(N)
class Solution {
    
    bool dfsDetectCycle(int node, int parent, vector<int> adj[]){
        
        vis[node] = 1 ;
        for(auto nb: adj[node]){
            if(vis[nb] == 0){
                if(dfsDetectCycle(nb, node, adj)) return true ;
            }
            else if(nb != parent){
                return true ;
            }
        }
        
        return false ;
    }
    
  public:
    vector<int> vis ;
    bool isCycle(int V, vector<int> adj[]) {
        vis = vector<int> (V, 0) ;
        bool cycle = false ; 
        
        for(int i=0 ; i < V ; i++){
            if(!vis[i]){
                cycle = dfsDetectCycle(i, -1, adj) ;
            }
            if(cycle) return true ;
        }
        
        return false ;
    }
};