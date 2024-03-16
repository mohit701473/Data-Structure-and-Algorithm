// LeetCode -> 238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // Intution -> PrefixSum
        // T.C. = O(n)
        // S.C. = O(1)
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i];
        }
        return res;
        
        /*
        int n = nums.size() ;    
        vector<int> prefixMulti(n, -1), suffixMulti(n, -1) ;
        vector<int> ans ;

        prefixMulti[0] = 1 ;
        suffixMulti[n-1] = 1 ;

        for(int i=1 ; i<n ; i++){
            prefixMulti[i] = prefixMulti[i-1] * nums[i-1] ;
            suffixMulti[n -i -1] = suffixMulti[n-i] * nums[n-i] ;
        }

        for(int k = 0 ; k<n ; k++){
            int product = prefixMulti[k] * suffixMulti[k] ;
            ans.push_back(product) ;
        }

        return ans ;

        */

    }
};