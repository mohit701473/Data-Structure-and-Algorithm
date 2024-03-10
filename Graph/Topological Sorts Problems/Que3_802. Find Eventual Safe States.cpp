// LeetCode -> 802. Find Eventual Safe States
https://leetcode.com/problems/find-eventual-safe-states/description/



// T.C. = O(V + E) + O(Vlog(V))
// S.C. = O()
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size() ;
        vector<int> adj[V] ;
        vector<int> indegree(V, 0) ;
        queue<int> q ;
        vector<int> topoSort ; // this will stotre the Eventual Safe States
        
        // reverse the graph and compute teh indegree of the reversed graph
        for(int i=0 ; i<V ; i++){
            for(auto nb: graph[i]){
                adj[nb].push_back(i) ;
                indegree[i]++ ;
            }
        }

        // find the terminal nodes or nodes whose indegree is zero
        for(int i=0 ; i<V ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            topoSort.push_back(node) ;

            for(auto nb: adj[node]){
                indegree[nb]-- ;
                if(indegree[nb] == 0){
                q.push(nb) ;
            }
            }
        }
        
        sort(topoSort.begin(), topoSort.end()) ;

        return topoSort ;
    }
};