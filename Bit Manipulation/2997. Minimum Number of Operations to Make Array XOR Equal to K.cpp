// LeetCode -> 2997. Minimum Number of Operations to Make Array XOR Equal to K
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total_xor = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            total_xor ^= nums[i];
        }

        int diff = total_xor ^ k;

        int min_op = 0;

        while(diff){
            if(diff & 1){
                min_op++;
            }
            diff >>= 1;
        }

        return min_op;
    }
};