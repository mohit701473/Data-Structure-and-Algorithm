https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/


// Approch -> Array, Greedy, Sorting
// T.C. = O(Nlog(N)) + O(N)
// S.C. = O(N)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans ;
        sort(nums.begin(), nums.end()) ;

        for(int i=0 ; i < nums.size() ; i += 3){
            if((nums[i+2] - nums[i]) <= k){
                ans.push_back({nums[i], nums[i+1], nums[i+2]}) ;
            }
            else return {} ;
        }
        
        return ans ;
    }
};