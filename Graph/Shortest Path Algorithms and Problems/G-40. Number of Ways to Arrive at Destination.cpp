// LeetCode -> 1976. Number of Ways to Arrive at Destination
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/


// T.C. = Same As Dijkstra
#define ll long long
#define pll pair<ll, ll>

class Solution {
public:

    int MOD = 1e9 + 7;

    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);


// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------

        
        int mod = (int) (1e9+7) ;
        vector<pair<int, int>> adj[n] ;
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]}) ;
            adj[it[1]].push_back({it[0], it[2]}) ;
        }

        vector<int> dist(n, INT_MAX), ways(n, 0) ;
        dist[0] = 0 ;
        ways[0] = 1 ;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
        pq.push({0, 0}) ;

        while(!pq.empty()){
            int dis = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;

            if(dis > dist[node]) continue ;

            for(auto it: adj[node]){
                int adjNode = it.first ;
                int edW = it.second ;

                if((long long)dis + (long long)edW < dist[adjNode]){
                    dist[adjNode] = dis + edW ;
                    ways[adjNode] = ways[node] ;
                    pq.push({dist[adjNode], adjNode}) ;
                }
                else if((long long)dis + (long long)edW == dist[adjNode]){
                    ways[adjNode] += ways[node] % mod  ;
                }
            }
        }

        if(ways[n-1] == 0)
        return 1 ;

        return ways[n-1] % mod  ;
        
    }
};