// LeetCode -> 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/



class Solution {
public:

    void floydWarshall(vector<vector<int>>&matrix){
	    int n = matrix.size() ;
	    
	    for(int i=0 ; i<n ; i++){
	        matrix[i][i] = 0 ;
	    }
	    
	    // floyd warshLL
	    for(int via=0 ; via<n ; via++){
	        for(int i=0 ; i<n ; i++){
	            for(int j=0 ; j<n ; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]) ;
	            }
	        }
	    }
	    
	    // check for negative weight cycle
	    for(int i=0 ; i<n ; i++){
	        if(matrix[i][i] < 0){
	            // negative cycle 
	        }
	    }
	    
	    
	    // for(int i=0 ; i<n ; i++){
	    //     for(int  j=0 ; j<n ; j++){
	    //         if(matrix[i][j] == 1e9){
	    //             matrix[i][j] = -1 ;
	    //         }
	    //     }
	    // }
	}


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9)) ;
        for(auto it: edges){
            int u = it[0] ;
            int v = it[1] ;
            int wt = it[2] ;

            matrix[u][v] = wt ;
            matrix[v][u] = wt ;
        }

        floydWarshall(matrix) ;

        int cntCities = INT_MAX, city = -1 ;
        for(int i=0 ; i<n ; i++){
            int cnt = 0 ;
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] <= distanceThreshold){
                    cnt++ ;
                }
            }

            if(cnt <= cntCities){
                cntCities = cnt ;
                city = i ;
            }
        }

        return city ;
    }
};