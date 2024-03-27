// LeetCode -> 442. Find All Duplicates in an Array
https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Similar Questions 
// (I) LeetCode -> 41. First Missing Positive
       https://leetcode.com/problems/first-missing-positive/description/

// (II)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp ;
        
        for(auto &it: nums) mp[it]++ ;

        vector<int> ans ;
        for(auto &it: mp){
            if(it.second > 1)
                ans.push_back(it.first) ;
        }

        return ans ;
    }
};