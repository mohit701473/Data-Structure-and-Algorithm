// https://leetcode.com/problems/minimum-time-to-repair-cars/description/

class Solution {
    public:
        bool isValidTime(vector<int>& ranks, long long cars, long long mid) {
            int n = ranks.size();
    
            for (int i = 0; i < n; i++) {
                long long repairCnt = sqrt(mid / ranks[i]);
                cars -= repairCnt;
            }
    
            return cars <= 0;
        }
    
        long long repairCars(vector<int>& ranks, int cars) {
            long long st = 1, end = cars * 1ll * 100 * cars, ans = 0;
    
            while (st <= end) {
                long long mid = st + (end - st) / 2;
    
                if (isValidTime(ranks, cars, mid)) {
                    ans = mid;
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
    
            return ans;
        }
    };