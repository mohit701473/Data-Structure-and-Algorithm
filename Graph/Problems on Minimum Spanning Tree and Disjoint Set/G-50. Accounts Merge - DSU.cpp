// LeetCode -> 721. Accounts Merge
https://leetcode.com/problems/accounts-merge/description/



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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ;
        unordered_map<string, int> mapMail ;
        DisjointSet ds(n) ;

        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                string mail = accounts[i][j] ;

                if(mapMail.find(mail) == mapMail.end()){
                    mapMail[mail] = i ;
                }
                else{
                    ds.unionBySize(i, mapMail[mail]) ;
                }
            }
        }

        vector<string> mergeMail[n] ;
        for(auto &it: mapMail){
            string mail = it.first ;
            int node = ds.findUPar(it.second) ;

            mergeMail[node].push_back(mail) ;
        }

        vector<vector<string>> ans ;
        for(int i=0 ; i<n ; i++){
            if(mergeMail[i].size() == 0) continue ;
            sort(mergeMail[i].begin(), mergeMail[i].end()) ;
            vector<string> temp ;
            temp.push_back(accounts[i][0]) ;

            for(auto &it: mergeMail[i]){
                temp.push_back(it) ;
            }

            ans.push_back(temp) ;
        }

        return ans ;
    }
};