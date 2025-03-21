// https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15

class Solution {
    public:
        bool isPossibleCapability(vector<int>& nums, int k, int cap) {
            int i = 0, n = nums.size();
    
            while (i < n) {
                if (nums[i] <= cap) {
                    i++;
                    k--;
                }
                i++;
            }
    
            return (k <= 0);
        }
    
        int minCapability(vector<int>& nums, int k) {
            int l = INT_MAX, r = INT_MIN, ans = 0;
    
            for (auto num: nums) {
                l = min(l, num);
                r = max(r, num);
            }
    
            while (l <= r) {
                int mid = l + (r - l) / 2;
    
                if (isPossibleCapability(nums, k, mid)) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
    
            return ans;
        }
    };