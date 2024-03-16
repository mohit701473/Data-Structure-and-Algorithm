// GFG -> Minimum Spanning Tree
https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1


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


class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges ;
        // O(V + E)
        for(int i=0 ; i<V ; i++){
            for(auto it: adj[i]){
                int u = i ;
                int v = it[0] ;
                int wt = it[1] ;
                // here you are inserting a eadge twice bcz it is an undirected graph
                // there is no issue bcz we are using a disjoinSet data struce by which this is managed
                edges.push_back({wt, {u, v}}) ;
            }
        }
        
        // O(E*log(E))
        sort(edges.begin(), edges.end()) ;
        
        DisjointSet ds(V) ;
        int mstSum = 0 ;
        
        // O(E)
        for(auto it: edges){
            int wt = it.first ;
            int u = it.second.first ;
            int v = it.second.second ;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstSum += wt ;
                ds.unionBySize(u, v) ;
            }
        }
        
        return mstSum ;
    }
};