// LeetCode ->  547. Number of Provinces
https://leetcode.com/problems/number-of-provinces/description/


// Approch -> DFS
// T.C. = O(V) + O(V +2E)
// S.C. = O(2N)
class Solution {

    void dfsTraversal(int node, vector<vector<int>> &isConnected, vector<int> &vis){

        vis[node] = 1 ;

        for(int i=0 ; i<isConnected[node].size() ; i++){
            int nb = isConnected[node][i] ;
            if(!vis[i] && nb){
                vis[i] = 1 ;
                dfsTraversal(i, isConnected, vis) ;
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        vector<int> vis(n, 0) ;
        int provinces = 0 ;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfsTraversal(i, isConnected, vis) ;
                provinces++ ;
            }
        }

        return provinces ;
    }
};