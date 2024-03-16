// GFG -> Number of Provinces
https://www.geeksforgeeks.org/problems/number-of-provinces/1




// Expected Time Complexity: O(V2)
// Expected Auxiliary Space: O(V)

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
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V) ;
        // O(V + E)
        for(int i=0 ; i<V ; i++){
            for(int j=0 ; j<V ; j++){
                // here you are inserting a eadge twice bcz it is an undirected graph
                // there is no issue bcz we are using a disjoinSet data struce by which this is managed
                if(adj[i][j]){
                    ds.unionBySize(i, j) ;
                }
            }
        }
        
        int cntDistinctUltimateParents = 0 ;
        
        for(int i=0 ; i<V ; i++){
            if(ds.parent[i] == i){
                cntDistinctUltimateParents++ ;
            }
        }
        
        return cntDistinctUltimateParents;
    }
    
    
    
    
};
