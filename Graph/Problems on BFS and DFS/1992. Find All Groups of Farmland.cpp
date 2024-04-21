// LeetCode -> 1992. Find All Groups of Farmland
https://leetcode.com/problems/find-all-groups-of-farmland/description/



class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& land, int &r2, int &c2){
        land[i][j] = 2 ;
        int n = land.size(), m = land[0].size() ;
        int dRow[] = {-1, 1, 0, 0} ;
        int dCol[] = {0, 0, -1, 1} ;

        for(int k=0 ; k<4 ; k++){
            int nb_i = i + dRow[k] ;
            int nb_j = j + dCol[k] ;

            if(nb_i >= 0 && nb_i < n && nb_j >= 0 && nb_j < m){
                if(land[nb_i][nb_j] == 1){
                    if(nb_i + nb_j > r2 + c2){
                        r2 = nb_i, c2 = nb_j ;
                    }

                    dfs(nb_i, nb_j, land, r2, c2) ;
                }
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans ;
        int n = land.size(), m = land[0].size() ;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(land[i][j] == 1){
                    int r2 = i, c2 = j ;
                    dfs(i, j, land, r2, c2) ;
                    ans.push_back({i, j, r2, c2}) ;
                }
            }
        }

        return ans ;
    }
};