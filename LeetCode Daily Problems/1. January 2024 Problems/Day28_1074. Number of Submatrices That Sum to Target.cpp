https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

// Approch -> Generate All The Submarices and Find The answer
// T.C. = O((m * n)^3)
// S.C. = O(1)
class Solution {

    int sumOfTheSubMatrix(vector<vector<int>> &matrix, int rStart, int rSize, int cStart, int cSize){
        int sum = 0 ;

        for(int i = rStart ; i < rStart + rSize ; i++){
            for(int j = cStart ; j < cStart + cSize ; j++){
                sum += matrix[i][j] ;
            }
        }

        return sum ;
    }

    int generateAllSubmatrix(vector<vector<int>> &matrix, int target){
        int ans = 0, m = matrix.size(), n = matrix[0].size() ;

        for(int rowStart = 0 ; rowStart < m ; rowStart++){
            for(int rowSize = 1 ; rowStart + rowSize <= m ; rowSize++){
                for(int colStart = 0 ; colStart < n ; colStart++){
                    for(int colSize = 1 ; colStart + colSize <= n ; colSize++){
                        if(sumOfTheSubMatrix(matrix, rowStart, rowSize, colStart, colSize) == target)
                            ans++ ;
                    }
                }
            }
        }

        return ans ;
    }
    
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        return generateAllSubmatrix(matrix, target) ;
    }
};