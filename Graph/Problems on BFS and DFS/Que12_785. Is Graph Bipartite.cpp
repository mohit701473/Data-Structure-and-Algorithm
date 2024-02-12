// LeetCode -> 785. Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/



// Approch -> BFS
// T.C. = O(V + 2E) + O(V)
// S.C. = O(V) + O(V)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> color(n, -1) ;
        queue<int> q ;

        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                // BFS
                q.push(i) ;
                color[i] = 0 ;

                while(!q.empty()){
                    int node = q.front() ;
                    q.pop() ;

                    for(auto nb: graph[node]){
                        if(color[nb] == color[node]){
                            return false ;
                        }
                        else{
                            if(color[nb] == -1){
                                q.push(nb) ;
                                color[nb] = !color[node] ;
                            }
                        }
                    }
                }
            }
        }

        return true ;
    }
};



// Approch -> DFS
// T.C. = O(n + 2E) + O(n)
// S.C. = O(n) + O(n)
class Solution {

    void dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colorVec, bool &ans){
        colorVec[node] = color ;

        if(!ans) return ;

        for(auto nb: graph[node]){
            if(colorVec[nb] == colorVec[node]){
                ans = false ;
                return ;
            }
            else{
                if(colorVec[nb] == -1){
                    dfs(nb, !colorVec[node], graph, colorVec, ans) ;
                }
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> color(n, -1) ;
        

        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                bool ans = true ;
                dfs(i,0, graph, color, ans) ;
                if(!ans) {
                    return false ;
                }
            }
        }

        return true ;
    }
};