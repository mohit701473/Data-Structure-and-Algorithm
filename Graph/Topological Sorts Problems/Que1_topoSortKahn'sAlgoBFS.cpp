// GFG -> Topological sort
https://www.geeksforgeeks.org/problems/topological-sort/1


// T.C. = O(V + E)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo ;
	    vector<int> indegree(V, 0) ;
	    queue<int> q ;
	    
	    // set the iondegree of the nodes
	    for(int i=0 ; i<V ; i++){
	        for(auto nb: adj[i]){
	            indegree[nb]++ ;
	        }
	    }
	    
	    // pickup the node whose indegree is zero and insert them into queue
	    for(int i=0 ; i<V ; i++){
	        if(indegree[i] == 0){
	            q.push(i) ;
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front() ;
	        q.pop() ;
	        topo.push_back(node) ;
	        
	        for(auto nb: adj[node]){
	            indegree[nb]-- ;
	            if(indegree[nb] == 0){
    	            q.push(nb) ;
    	        }
	        }
	    }
	    
	    return topo ;
	}
};