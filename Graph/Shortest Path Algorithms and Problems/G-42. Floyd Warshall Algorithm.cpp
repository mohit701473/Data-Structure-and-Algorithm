// GFG -> Floyd Warshall
https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


// Expected Time Complexity: O(n3)
// Expected Space Complexity: O(1)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size() ;
	    
	    for(int i=0 ; i<n ; i++){
	        for(int  j=0 ; j<n ; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9 ;
	            }
	        }
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
	    
	    
	    for(int i=0 ; i<n ; i++){
	        for(int  j=0 ; j<n ; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1 ;
	            }
	        }
	    }
	}
};