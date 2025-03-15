// https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13

class Solution {
    public:
        int n, q;
    
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
            vector<int> diffArr(n, 0);
    
            for (int i = 0; i <= k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int x = queries[i][2];
    
                diffArr[l] += x;
                if (r + 1 < n) diffArr[r + 1] -= x;            
            }
    
            int cumSum = 0;
            for(int i = 0; i < n; i++) {
                cumSum += diffArr[i];
                diffArr[i] = cumSum;
                if(nums[i] - diffArr[i] > 0) {
                    return false;
                }
            }
    
            return true;
        }
        
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            n = nums.size();
            q = queries.size();
    
            long long sum  = 0;
            for (auto num: nums) sum +=  num;
            if (sum == 0) return 0;
    
            int st = 0, end = q - 1, k = -1;
            while (st <= end) {
                int mid = (st + end) / 2;
    
                if (isZeroArray(nums, queries, mid)) {
                    k = mid + 1;
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            
            return k;
        }
    };