// GFG -> BFS of graph
https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs ;
        vector<int> vis(V, 0) ;
        queue<int> q ;
        q.push(0) ;
        vis[0] = 1 ;
        
        while(!q.empty()){
            // step -> 1: pop from queue and print
            int node = q.front() ;
            q.pop() ;
            bfs.push_back(node) ;
            
            // step -> 2: insert all neighbors of the node into queue
            for(auto nb: adj[node]){
                if(!vis[nb]){
                    q.push(nb) ;
                    vis[nb] = 1 ;
                }
            }
        }
        
        return bfs ;
    }
};