// LeetCode -> 310. Minimum Height Trees
/*
    Company Tags   : GOOGLE
    Leetcode Link  : https://leetcode.com/problems/minimum-height-trees/
*/

//NOTE : You can do a brute force to do DFS from each node treating them as root and keep finding the Height in every case. That will give TLE.

/**************************************************** C++ ********************************************/
//Using Topological Sorting
//T.C : O(V+E)
//S.C : O(V+E)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> res;
        queue<int> que;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // put the all leaf nodes into queue
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1)
                que.push(i);
        }

        // go to the center using the leaf nodes of the tree
        while(n > 2){
            int size = que.size();
            n -= size;

            while(size--){
                int node = que.front();
                que.pop();

                for(int nb: adj[node]){
                    indegree[nb]--;
                    if(indegree[nb] == 1){
                        que.push(nb);
                    }
                }
            }
        }

        // now queue have only 1 or 2 nodes which is your root
        while(!que.empty()){
            res.push_back(que.front());
            que.pop();
        }

        return res;
    }
};