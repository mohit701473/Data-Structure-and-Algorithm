// LeetCode -> 1319. Number of Operations to Make Network Connected
https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/


// Another Approch -> Disjoint Set data structure and cont the no. of extra edges


// Approch -> DFS and Count the components
// T.C. = O(V + E)
// S.C. = O(V)
class Solution {

    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1 ;

        for(auto nb: adj[node]){
            if(!vis[nb]){
                dfs(nb, adj, vis) ;
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1 ;

        vector<int> adj[n] ;
        vector<int> vis(n, 0) ;
        int cnt = 0 ;

        for(auto &it: connections){
            int a_i = it[0] ;
            int b_i = it[1] ;

            adj[a_i].push_back(b_i) ;
            adj[b_i].push_back(a_i) ;
        }

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                cnt++ ;
                dfs(i, adj, vis) ;
            }
        }

        return cnt-1 ;
    }
};