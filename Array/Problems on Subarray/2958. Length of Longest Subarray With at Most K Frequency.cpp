// LeetCode -> 2958. Length of Longest Subarray With at Most K Frequency
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

// Approch -> Sliding Window + Hash Table
// T.C. = O(2n)
// S.C. = O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, maxLen = -1 ;
        int n = nums.size() ;
        unordered_map<int, int> freq ;

        while(j < n){
            freq[nums[j]]++ ;

            while(freq[nums[j]] > k){
                freq[nums[i]]-- ;
                i++ ;
            }

            maxLen = max(maxLen, (j-i+1)) ;
            j++ ;
        }

        return maxLen ;
    }
};