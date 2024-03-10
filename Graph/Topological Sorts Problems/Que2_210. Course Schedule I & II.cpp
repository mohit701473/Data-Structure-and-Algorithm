// LeetCode ->210. Course Schedule II
https://leetcode.com/problems/course-schedule-ii/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses] ;
        vector<int> topo ;
	    vector<int> indegree(numCourses, 0) ;
	    queue<int> q ;

        // create a adjcency list for courses
        for(int i=0 ; i<prerequisites.size() ; i++){
            int a_i = prerequisites[i][0] ;
            int b_i = prerequisites[i][1] ;
            adj[b_i].push_back(a_i) ;
        }
	    
	    // set the iondegree of the nodes
	    for(int i=0 ; i<numCourses ; i++){
	        for(auto nb: adj[i]){
	            indegree[nb]++ ;
	        }
	    }
	    
	    // pickup the node whose indegree is zero and insert them into queue
	    for(int i=0 ; i<numCourses ; i++){
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

        if(topo.size() == numCourses)
            return topo ;
	    
	    return {} ;
    }
};