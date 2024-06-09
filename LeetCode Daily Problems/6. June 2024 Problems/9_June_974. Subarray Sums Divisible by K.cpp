https://leetcode.com/problems/subarray-sums-divisible-by-k/

// another same qiuestion is: 523. Continuous Subarray Sum
https://leetcode.com/problems/continuous-subarray-sum/
/*
Why u should convert negative reminder into positve?
exploitation -> [-1,2,9] explore this test case without conversion.

if u want to print all the subarrays use can use
unordered_map<int, vector<int>> prefix;
where in vector u can store the indecis of the subarrays.
*/


// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix; // <sum, len>
        prefix[0] = 1;
        int ans = 0, sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k;
            rem = rem < 0 ? rem + k : rem;

            if(prefix.find(rem) != prefix.end()){
                ans += prefix[rem];
            }

            prefix[rem]++;
        }
        return ans;
    }
};