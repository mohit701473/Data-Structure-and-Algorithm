// LeetCode -> 992. Subarrays with K Different Integers
https://leetcode.com/problems/subarrays-with-k-different-integers/description/



// Approch -> Sliding Window + Hashing
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:

    int slidingWindow(vector<int>& nums, int k){
        if(k == 0) return 0 ;

        int n = nums.size() ;
        int i = 0, j = 0, cnt = 0 ;
        unordered_map<int, int> mp ;

        while(j < n){
            mp[nums[j]]++ ;

            while(mp.size() > k){
                mp[nums[i]]-- ;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]) ;
                }
                i++ ;
            }

            cnt += (j - i + 1) ;
            j++ ;
        }

        return cnt ;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1) ;
    }
};