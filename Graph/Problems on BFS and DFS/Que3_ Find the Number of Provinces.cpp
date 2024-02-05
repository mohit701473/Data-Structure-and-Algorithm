// Coding Ninja ->  Find the Number of Provinces
https://www.codingninjas.com/studio/problems/find-the-number-of-states_1377943


// Approch -> DFS
// T.C. = O(V) + O(V +2E)
// S.C. = O(2N)
void dfsTraversal(int node, vector<vector<int>> &roads, vector<int> &vis){

    vis[node] = 1 ;

    for(int i=0 ; i<roads[node].size() ; i++){
        int nb = roads[node][i] ;
        if(!vis[i] && nb){
            vis[i] = 1 ;
            dfsTraversal(i, roads, vis) ;
        }
    }
}

int findNumOfProvinces(vector<vector<int>> &roads, int n) {

    vector<int> vis(n, 0) ;
    int provinces = 0 ;

    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfsTraversal(i, roads, vis) ;
            provinces++ ;
        }
    }

    return provinces ;
}