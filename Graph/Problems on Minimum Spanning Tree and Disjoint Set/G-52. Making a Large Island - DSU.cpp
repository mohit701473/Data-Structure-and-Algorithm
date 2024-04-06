// LeetCode -> 827. Making A Large Island
https://leetcode.com/problems/making-a-large-island/description/


class DisjointSet{
public:
    vector<int> parent, rank, size ;

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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        DisjointSet ds(n * n) ;
        int dr[] = {-1, 0, 1, 0} ;
        int dc[] = {0, 1, 0, -1} ;
        int ans = -1 ;

        // step 1 -> First make the connected components from 1's
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(grid[i][j] == 0) continue ;

                for(int idx=0 ; idx<4 ; idx++){
                    int adjr = i + dr[idx] ;
                    int adjc = j + dc[idx] ;
                    
                    if( (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n) && (grid[adjr][adjc] == 1) ){
                        // valid && also adjNode == 1
                        int nodeNo = i * n + j ;
                        int adjNodeNo = adjr * n + adjc ;
                        ds.unionBySize(nodeNo, adjNodeNo) ; // connect them 
                    }
                }
            }
        }

        // step 2 -> Convert to 0's to 1 and compute maximum connected ones
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(grid[i][j] == 1) continue ;

                set<int> components ;
                for(int idx=0 ; idx<4 ; idx++){
                    int adjr = i + dr[idx] ;
                    int adjc = j + dc[idx] ;
                    
                    if( adjr >= 0 && adjr < n && adjc >= 0 && adjc < n ){
                        // valid 
                        int nodeNo = i * n + j ;
                        int adjNodeNo = adjr * n + adjc ;
                        if(grid[adjr][adjc] == 1){
                            components.insert(ds.findUPar(adjNodeNo)) ;
                        }
                    }
                }

                int size = 0 ;
                for(auto it: components){
                    size += ds.size[it] ;
                }

                ans = max(ans, size+1) ;
            }
        }

        // checl if grid have all cell equal to on zero ius there in grid
        for(int cellNo = 0 ; cellNo < n * n ; cellNo++){
            ans = max(ans, ds.size[ds.findUPar(cellNo)]) ;
        }

        return ans ;
    }
};