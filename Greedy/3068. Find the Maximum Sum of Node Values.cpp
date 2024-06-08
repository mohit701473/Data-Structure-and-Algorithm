// LeetCode -> 3068. Find the Maximum Sum of Node Values
https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/


// optimal solution
class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int count = 0;
        ll idealSum = 0;
        ll nuksan = INT_MAX;
        ll profit = INT_MAX;

        for(ll it: nums){
            if((it ^ k) > it){
                idealSum += (it ^ k);
                count++;
                profit = min(profit, ((it ^ k) - it));
            }
            else{
                idealSum += it;
                nuksan = min(nuksan, (it - (it ^ k)));
            }
        }

        // x-or of nodes are done in pairs then count is even
        if((count & 1) == 0){
            return idealSum;
        }

        // clount is odd
        if(profit > nuksan){
            return idealSum - nuksan;
        }

        return idealSum - profit;
    }
};


// T.C. = O(nlog(n))
class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<ll> fayda;
        ll normalSum = 0;

        for(int i = 0; i < nums.size(); i++){
            normalSum += nums[i];

            fayda.push_back((nums[i] ^ k) - nums[i]);
        }

        sort(fayda.begin(), fayda.end(), greater<int>());

        int n = fayda.size();

        for(int i = 0; i < n-1; i += 2){
            ll pairSum = fayda[i] + fayda[i+1];

            if(pairSum > 0){
                normalSum += pairSum;
            }
        }

        return normalSum;
    }
};