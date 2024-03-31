// LeetCode -> 2444. Count Subarrays With Fixed Bounds
https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size() ;
        int minKPosition = -1 ;
        int maxKPosition = -1 ;
        int culpritPosition = -1 ;
        long long res = 0 ;

        for(int i=0 ; i<n ; i++){

            if(nums[i] < minK || nums[i] > maxK){
                culpritPosition = i ;
            }

            if(nums[i] == minK){
                minKPosition = i ;
            }

            if(nums[i] == maxK){
                maxKPosition = i ;
            }

            long long smaller = min(minKPosition, maxKPosition) ;
            long long temp = smaller - culpritPosition ;

            res += (temp <= 0) ? 0 : temp ;
        }

        return res ;
    }
};