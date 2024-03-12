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
        set<pair<int, int>> st ;
        vector<int> dist(V, INT_MAX) ;
        
        dist[S] = 0 ;
        st.insert({0, S}) ; // {dist, node}
        
        while(!st.empty()){
            auto it = *(st.begin()) ;
            int dis = it.first ;
            int node = it.second ;
            st.erase(it) ;
            
            for(auto itt: adj[node]){
                int adjNode = itt[0] ;
                int edgeWeight = itt[1] ;
                
                if(dist[adjNode] > (dis + edgeWeight)){
                    // erase the not batter path
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode], adjNode}) ;
                    }
                    dist[adjNode] = dis + edgeWeight ;
                    st.insert({dist[adjNode], adjNode}) ;
                }
            }
        }
        
        return dist ;
    }
};