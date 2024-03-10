// GFG -> Topological sort
https://www.geeksforgeeks.org/problems/topological-sort/1


// T.C. = O(V + E)
class Solution
{
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        
        vis[node] = 1;
        
        for(auto nb: adj[node]){
            if(!vis[nb]){
                dfs(nb, adj, vis, st) ;
            }
        }
        
        st.push(node) ;
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0) ;
	    stack<int> st ;
	    vector<int> topo ;
	    
	    for(int i=0 ; i<V ; i++){
	        if(!vis[i]){
	            dfs(i, adj, vis, st) ;
	        }
	    }
	    
	    while(!st.empty()){
	        topo.push_back(st.top()) ;
	        st.pop() ;
	    }
	    
	    return topo ;
	}
};