// GFG -> Shortest Path in Weighted undirected graph
https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1


// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n)
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>> adjList[n+1] ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
        vector<int> dist(n+1, INT_MAX) ;
        vector<int> parent(n+1, 0) ;
        vector<int> ans ;
        
        for(auto it: edges){
            int u = it[0] ;
            int v = it[1] ;
            int w = it[2] ;
            
            adjList[u].push_back({v, w}) ;
            adjList[v].push_back({u, w}) ;
        }
        
        pq.push({0, 1}) ;
        dist[1] = 0 ;
        
        while(!pq.empty()){
            int dis = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;
            
            for(auto it: adjList[node]){
                int adjNode = it[0] ;
                int weight = it[1] ;
                
                if(weight + dis < dist[adjNode]){
                    dist[adjNode] = weight + dis ;
                    parent[adjNode] = node ;
                    pq.push({dist[adjNode], adjNode}) ;
                }
            }
        }
        
        if(dist[n] == INT_MAX){
            return {-1} ;
        }
        
        int node = n ;
        while(parent[node] != node){
            ans.push_back(node) ;
            node = parent[node] ;
        }
        
        ans.push_back(1) ;
        ans.push_back(dist[n]) ;
        reverse(ans.begin(), ans.end()) ;
        
        return ans ;
    }
};