// LeetCode -> 787. Cheapest Flights Within K Stops
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


// T.C. = O(E) => E = flights.size()
// Optimal Answer
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adjList[n] ;
        queue<pair<int, pair<int, int>>> q ; // {stops, {node, dist}}
        vector<int> dist(n, INT_MAX) ;

        // decleare the adjecency list
        for(auto it: flights){
            int from_i  = it[0] ;
            int to_i    = it[1] ;
            int price_i = it[2] ;

            adjList[from_i].push_back({to_i, price_i}) ;
        }

        q.push({0, {src, 0}}) ;
        dist[src] = 0 ;

        while(!q.empty()){
            auto it = q.front() ;
            q.pop() ;
            int stops = it.first ;
            int node = it.second.first ;
            int cost = it.second.second ;

            if(stops > K) continue ;

            for(auto adjNb: adjList[node]){
                int nb = adjNb.first ;
                int weight = adjNb.second ;

                if(cost + weight < dist[nb] && stops <= K){
                    dist[nb] = cost + weight ;
                    q.push({stops+1, {nb, dist[nb]}}) ;
                }
                
            }
        }

        return dist[dst] != INT_MAX ? dist[dst] : -1 ;
    }
};






class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adjList[n] ;
        queue<pair<int, pair<int, int>>> q ; // {node, {price, k}}
        vector<int> dist(n, INT_MAX) ;

        // decleare the adjecency list
        for(auto it: flights){
            int from_i  = it[0] ;
            int to_i    = it[1] ;
            int price_i = it[2] ;

            adjList[from_i].push_back({to_i, price_i}) ;
        }

        q.push({src, {0, K}}) ;
        dist[src] = 0 ;

        while(!q.empty()){
            int node = q.front().first ;
            int price = q.front().second.first ;
            int k = q.front().second.second ;
            q.pop() ;

            for(auto adjNb: adjList[node]){
                int nb = adjNb.first ;
                int weight = adjNb.second ;

                if(nb == dst && k >= 0){
                    dist[nb] = min(dist[nb], weight + price) ;
                }
                else{
                    if(k > 0 && weight + price < dist[nb]){
                        dist[nb] = weight + price ;
                        q.push({nb, {dist[nb], k-1}}) ;
                    }
                }
            }
        }

        return dist[dst] != INT_MAX ? dist[dst] : -1 ;
    }
};