#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005; // Maximum number of cities
const int LOG = 20;      // For LCA binary lifting

vector<int> adj[MAXN];   // Adjacency list to represent the tree
int population[MAXN];    // Population of each city
int depth[MAXN];         // Depth of each node
int up[MAXN][LOG];       // Binary lifting table for LCA
int inTime[MAXN], outTime[MAXN]; // In and Out times for each node in DFS
int timer = 0;

// Preprocess the tree using DFS and setup LCA binary lifting table
void dfs(int node, int parent) {
    inTime[node] = ++timer;
    up[node][0] = parent;
    for (int i = 1; i < LOG; i++) {
        if (up[node][i-1] != -1)
            up[node][i] = up[up[node][i-1]][i-1];
        else
            up[node][i] = -1;
    }
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
    outTime[node] = ++timer;
}

// Function to check if u is an ancestor of v
bool isAncestor(int u, int v) {
    return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
}

// Function to find LCA of two nodes
int findLCA(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = LOG-1; i >= 0; i--) {
        if (up[u][i] != -1 && !isAncestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

// Function to count cities with population <= W on the path from U to V
int countCitiesOnPath(int u, int v, int W) {
    int lca = findLCA(u, v);
    int count = 0;

    // Helper function to count cities from node to LCA
    auto countToLCA = [&](int node) {
        while (node != lca) {
            if (population[node] <= W) count++;
            node = up[node][0];
        }
        if (population[lca] <= W) count++; // Check LCA itself
    };

    countToLCA(u); // Count from U to LCA
    countToLCA(v); // Count from V to LCA

    return count;
}

// Main function to process queries
vector<int> city_population (int N, vector<int> populationArr, vector<vector<int> > road, int Q, vector<vector<int> > cities) {
    // Set global population array
    for (int i = 1; i <= N; i++) {
        population[i] = populationArr[i-1];
    }

    // Build the adjacency list
    for (auto &edge : road) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Preprocess the tree with DFS
    dfs(1, -1);

    // Vector to store results of queries
    vector<int> results;

    // Process each query
    for (auto &query : cities) {
        int u = query[0], v = query[1], W = query[2];
        results.push_back(countCitiesOnPath(u, v, W));
    }

    return results;
}

int main() {
    // Example usage:

    int N = 5; // Number of cities
    vector<int> population = {10, 20, 30, 40, 50}; // Population of each city
    vector<vector<int> > road = {{1, 2}, {1, 3}, {2, 4}, {3, 5}}; // Roads between cities
    int Q = 2; // Number of queries
    vector<vector<int> > cities = {{4, 5, 25}, {2, 3, 35}}; // Queries

    // Call the function
    vector<int> result = city_population(N, population, road, Q, cities);

    // Output the results
    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}
