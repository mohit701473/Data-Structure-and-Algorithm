// GFG -> Minimum Spanning Tree
https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1



// T.C. = O(Elog(E))
// S.C. = O(V)
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0 ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
        vector<bool> vis(V, 0) ;
        pq.push({0, 0}) ;
        
        // T.C. = O(E)
        while(!pq.empty()){
            auto it = pq.top() ; // O(log(E))
            pq.pop() ; // O(log(E))
            int wt = it.first ;
            int node = it.second ;
            
            if(vis[node] == 1) continue ;
            vis[node] = 1 ;
            sum += wt ;
            
            for(auto itt: adj[node]){ // O(E)
                int adjNode = itt[0] ;
                int adjWt = itt[1] ;
                
                if(!vis[adjNode]){
                    pq.push({adjWt, adjNode}) ; // O(log(E))
                }
            }
        }
        
        return sum ;
    }
};