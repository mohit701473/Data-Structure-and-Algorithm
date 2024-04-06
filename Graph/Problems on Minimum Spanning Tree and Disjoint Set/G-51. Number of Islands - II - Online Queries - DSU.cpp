// GFG -> Number Of Islands
https://www.geeksforgeeks.org/problems/number-of-islands/1



class DisjointSet{

private:
    vector<int> parent, rank, size ;

public:
    DisjointSet(int n){
        size.resize(n+1, 1) ;
        rank.resize(n+1, 0) ; // n+1 bcz it might be garpg of 1 base indexing
        parent.resize(n+1) ;
        for(int i=0 ; i<= n ; i++){
            parent[i] = i ;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node ;
        }

        return parent[node] = findUPar(parent[node]) ;
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;

        if(ulp_u == ulp_v) return ; 

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u ;
        }
        else{
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++ ;
        }
    }


    void unionBySize(int u, int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;

        if(ulp_u == ulp_v) return ; 

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u] ;
        }
        else if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ; 
        }
        else{
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ;
        }
    }

};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m) ;
        vector<vector<int>> vis(n, vector<int> (m, 0)) ;
        int cnt = 0 ;
        vector<int> ans ;
        int dr[] = {-1, 0, 1, 0} ;
        int dc[] = {0, 1, 0, -1} ;
        
        for(auto it: operators){
            int row = it[0] ;
            int col = it[1] ;
            
            if(vis[row][col] == 1){
                ans.push_back(cnt) ;
                continue ;
            }
            
            vis[row][col] = 1 ;
            cnt++  ;
            
            for(int idx=0 ; idx<4 ; idx++){
                int adjr = row + dr[idx] ;
                int adjc = col + dc[idx] ;
                
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(vis[adjr][adjc] == 1){
                        int nodeNo = row * m + col ;
                        int adjNodeNo = adjr * m + adjc ;
                        
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                            cnt-- ;
                            ds.unionBySize(nodeNo, adjNodeNo) ;
                        }
                    }
                }
            }
            
            ans.push_back(cnt) ;
        }
        
        return ans ;
    }
};
