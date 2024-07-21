// LeetCode -> 2392. Build a Matrix With Conditions


class Solution {
public:
    bool getTopoSort(vector<unordered_set<int>>& adjList, vector<int>& topo) {
        int n = adjList.size();
        queue<int> q;
        vector<int> indegree(n, 0);

        for(int i = 1; i < n; i++) {
            for(auto nb: adjList[i])
                indegree[nb]++;
        }

        for(int i = 1; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto nb: adjList[node]) {
                indegree[nb]--;
                if(indegree[nb] == 0)
                    q.push(nb);
            }
        }

        return (topo.size() != n-1); // true -> cycle persent & false -> cycle is not persent
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n = rowConditions.size(), m = colConditions.size();
        vector<unordered_set<int>> rowAdjList(k+1), colAdjList(k+1);
        vector<int> rowTopo, colTopo;
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(auto& it: rowConditions) {
            int above = it[0];
            int below = it[1];
            rowAdjList[below].insert(above);
        }

        for(auto& it: colConditions) {
            int left = it[0];
            int right = it[1];
            colAdjList[right].insert(left);
        }

        if(getTopoSort(rowAdjList, rowTopo))
            return {};

        if(getTopoSort(colAdjList, colTopo))
            return {};


        unordered_map<int, int> col_idx;
        for(int i = 0; i < k; i++) {
            int val = colTopo[i];
            int idx = k-1-i;
            col_idx[val] = idx;
            cout << val << " ";
        }
        cout << endl;

        for(int idx = 0; idx < k; idx++) {
            int val = rowTopo[idx];
            int i = k-1-idx;
            int j = col_idx[val];
            ans[i][j] = val;
            cout << val << " ";
        }

        return ans;
    }
};