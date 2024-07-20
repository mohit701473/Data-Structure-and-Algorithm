// LeetCode -> 1605. Find Valid Matrix Given Row and Column Sums
https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/

/*
Test Cases -> rowSum = [4,12,10,1,0]
              colSum = [1,0,3,16,7]

T.C. = O(n + m)
S.C. = O(n * m)
*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(rowSum[i] == 0) {
                i++;
                continue;
            }

            if(colSum[j] == 0) {
                j++;
                continue;
            }

            if(rowSum[i] <= colSum[j]) {
                ans[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                rowSum[i] = 0;
                i++;
            } else {
                ans[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                colSum[j] = 0;
                j++;
            }
        }

        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
//         int n = rowSum.size(), m = colSum.size();
//         vector<vector<int>> ans(n, vector<int>(m, 0));
//         int i = 0, j = 0;
//         priority_queue<int, vector<int>, greater<int>> pq;

//         for(int k = 0; k < m; k++) {
//             if(colSum[k] != 0)
//                 pq.push(colSum[k]);
//         }

//         while(i < n && j < m) {
//             if(rowSum[i] == 0) {
//                 i++;
//                 continue;
//             }

//             if(colSum[j] == 0) {
//                 j++;
//                 continue;
//             }

//             if(rowSum[i] <= pq.top()) {
//                 ans[i][j] = rowSum[i];
//                 colSum[j] -= rowSum[i];
//                 rowSum[i] = 0;
//                 i++;
//             } else {
//                 ans[i][j] = pq.top();
//                 rowSum[i] -= pq.top();
//                 colSum[j] -= pq.top();
//                 pq.pop();
//                 j++;
//             }

//             pq = priority_queue<int, vector<int>, greater<int>> ();
//             for(int k = j; k < m; k++) {
//                 if(colSum[k] != 0)
//                     pq.push(colSum[k]);
//             }
//         }

//         return ans;
//     }
// };