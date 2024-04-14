// LeetCode -> 85. Maximal Rectangle
https://leetcode.com/problems/maximal-rectangle/description/


class Solution {
private:

    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }

    int largestRectangleArea(vector<int>& heights) {
         int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

public:

    vector<vector<int>> convertedMatrix(vector<vector<char>> &matrix, int row, int col){
        vector<vector<int>> M ;
        for(int i=0 ; i<row ; i++){
            vector<int> temp ;
            for(int j=0 ; j<col ; j++){

                if(matrix[i][j] == '0')
                    temp.push_back(0) ;
                else
                   temp.push_back(1) ;
            }
            M.push_back(temp) ;
        }

        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                
                if(i != 0){
                    if(M[i][j] == 0)
                        M[i][j] = 0 ;
                    else
                        M[i][j] = M[i][j] + M[i-1][j] ;
                }
            }
        }

        return M ;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size() ; 
        int col = matrix[0].size() ;
        int max_area = 0 ;
        vector<vector<int>> M = convertedMatrix(matrix, row, col) ;

        for(int i=0 ; i<row ; i++){
            int new_area = largestRectangleArea(M[i]) ;
            if(new_area > max_area)
                max_area = new_area ;
        }

        return max_area ;
    }
};