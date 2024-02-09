https://leetcode.com/problems/largest-divisible-subset/description/

// Approch -> DP same as LIS problem
// T.C. = O(n^2)
// S.C. = O(n) 
class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> lisLength(n, 1), prevIndex(n, -1) ;
        int maxLen = 0 , index = -1 ;

        sort(nums.begin(), nums.end()) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i] % nums[j] == 0 && 1 + lisLength[j] > lisLength[i]){
                    lisLength[i] = 1 + lisLength[j] ;
                    prevIndex[i] = j ;
                }
            }

            if(lisLength[i] > maxLen){
                maxLen = lisLength[i] ;
                index = i ;
            }
        }

        vector<int> ans ;
        while(index != -1){
            ans.push_back(nums[index]) ;
            index = prevIndex[index] ;
        }

        return ans ;
    }
};



// Approch -> 1: Not dp Approch
class Solution {

    void solve(int i, vector<int> &nums, vector<int> temp){

        if(i >= nums.size()){
            if(temp.size() > ans.size()){
                ans = temp ;
            }
            return ;
        }

        // not take 
        solve(i+1, nums, temp) ;

        // take
        if(temp.empty()){
            temp.push_back(nums[i]) ;
            solve(i+1, nums, temp) ;
        }
        else{
            int k = 0 ;
            for(k ; k<temp.size() ; k++){
                if(temp[k] % nums[i] != 0 && nums[i] % temp[k] != 0){
                    break ;
                }
            }
            if(k == temp.size()){
                temp.push_back(nums[i]) ;
                solve(i+1, nums, temp) ;
            }
        }
    }

public:
    vector<int> ans ;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp ;
        solve(0, nums,  temp) ;
        return ans ;
    }
};