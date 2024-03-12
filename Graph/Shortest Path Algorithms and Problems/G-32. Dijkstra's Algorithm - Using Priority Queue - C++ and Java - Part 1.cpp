// GFG -> Implementing Dijkstra Algorithm
https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// T.C. = O(Elog(V))
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
        vector<int> dist(V, INT_MAX) ;
        
        dist[S] = 0 ;
        pq.push({0, S}) ; // {dist, node}
        
        while(!pq.empty()){
            int dis = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;
            
            for(auto it: adj[node]){
                int adjNode = it[0] ;
                int edgeWeight = it[1] ;
                
                if(dist[adjNode] > (dis + edgeWeight)){
                    dist[adjNode] = dis + edgeWeight ;
                    pq.push({dist[adjNode], adjNode}) ;
                }
            }
        }
        
        return dist ;
    }
};