// #include <bits/stdc++.h>
// using namespace std;

// vector<long long> dfs(int node, vector<vector<int>>& adjList, vector<int>& vis, vector<long long>& ans, string& color) {
//     vis[node] = 1;  
    
//     int col = color[node] - '0';
//     vector<long long> temp = {0, 0, 0};  // {white_count, black_count, beauty_count}
//     temp[col]++;

//     for (auto nb: adjList[node]) {
//         if (!vis[nb]) {
//             vector<long long> temp_ans = dfs(nb, adjList, vis, ans, color);
//             temp[2] += temp_ans[2];
//             temp[2] += (col == 0 ? temp_ans[1] * temp[0] : temp_ans[0] * temp[1]);
//             temp[0] += temp_ans[0];
//             temp[1] += temp_ans[1];
//         }
//     }

//     ans[node-1] = temp[2];
//     return temp;
// }

// vector<long long> solve(int N, string color, vector<vector<int>>& Edges) {
//     cout << "String :" << color << endl;
//     vector<vector<int>> adjList(N+1);
//     vector<long long> ans(N, 0);
//     vector<int> vis(N+1, 0);

//     for (auto it: Edges) {
//         int u = it[0];
//         int v = it[1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
//     string colour = "";
//     for (auto ch: color)
//         colour += ch;

//     dfs(1, adjList, vis, ans, colour);
//     return ans;
// }

// int main() {
//     int N;
//     cout << "Enter the number of vertices (N): ";
//     cin >> N;

//     string color;
//     cout << "Enter the color string: ";
//     cin >> color;
//     cout << "String :" << color << endl;

//     vector<vector<int>> Edges;
//     cout << "Enter the edges (each line contains two integers representing an edge):" << endl;
//     for (int i = 0; i < N - 1; i++) {
//         vector<int> temp(2);
//         for (int j = 0; j < 2; j++)
//             cin >> temp[j];

//         Edges.push_back(temp);        
//     }

//     vector<long long> result = solve(N, color, Edges);

//     cout << "Beauty of each vertex: ";
//     for (auto val : result) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestSquareArea(vector<int>& histogram) {
    int n = histogram.size();
    stack<int> st;
    int maxSquareArea = 0;

    for (int i = 0; i <= n; ++i) {
        int h = (i == n ? 0 : histogram[i]);
        
        while (!st.empty() && h < histogram[st.top()]) {
            int height = histogram[st.top()];
            st.pop();
            int width = (st.empty() ? i : i - st.top() - 1);
            int side = min(height, width);
            maxSquareArea = max(maxSquareArea, side * side);
        }
        
        st.push(i);
    }

    return maxSquareArea;
}

int main() {
    vector<int> histogram = {1, 2, 3, 2, 1};
    cout << "Largest square area: " << largestSquareArea(histogram) << endl;

    histogram = {4, 3, 4};
    cout << "Largest square area: " << largestSquareArea(histogram) << endl;

    histogram = {11, 2, 3, 2, 11};
    cout << "Largest square area: " << largestSquareArea(histogram) << endl;

    return 0;
}
