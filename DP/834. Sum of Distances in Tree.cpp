// LeetCode -> 834. Sum of Distances in Tree



// BFS Solution
class Solution {
public:

    int bfs(int src, vector<int> adj[], int n){
        vector<int> vis(n, 0);
        int distance = 0;
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            distance += size * level;

            for(int i = 0; i<size; i++){
                int node = q.front();
                q.pop();

                for(auto nb: adj[node]){
                    if(!vis[nb]){
                        q.push(nb);
                        vis[nb] = 1;
                    }
                }
            }

            level++;
        }

        return distance;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            int dis_sum = bfs(i, adj, n);
            ans.push_back(dis_sum);
        }

        return ans;
    }
};



// DFS Solution
class Solution {
public:

    int solve(int node, int level, vector<int> adj[],  vector<int>& vis){
        vis[node] = 1;
        if(adj[node].size() == 0)
            return level;

        int dis = 0;
        for(auto nb: adj[node]){
            if(!vis[nb]){
                dis += solve(nb, level+1, adj, vis);
            }
        }

        return dis + level;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);
            int dis_sum = solve(i, 0, adj, vis);
            ans.push_back(dis_sum);
        }

        return ans;
    }
};