https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

// Approch -> Greedy, PrefixSum
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size() ;
        long long  ans = 0 ;
        long long rSum = 0 ; // remaining sum 

        sort(nums.begin(), nums.end()) ;

        for(int i=0 ; i<n ; i++){
            if(nums[i] < rSum){
                ans = rSum + nums[i] ;
            }

            rSum += nums[i] ;
        }

        return (ans == 0 ? -1 : ans) ;
    }
};