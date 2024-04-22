// LeetCode -> 1971. Find if Path Exists in Graph
https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:

    bool dfs(int node, vector<int> adj[], vector<int> &vis, int dst){
        if(node == dst) 
            return true;

        vis[node] = 1;

        for(auto nb: adj[node]){
            if(!vis[nb] && dfs(nb, adj, vis, dst))
                return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(source, adj, vis, destination);
    }
};