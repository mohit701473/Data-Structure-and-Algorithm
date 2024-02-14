https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {    
        int n = nums.size() ;
        vector<int> ans(n,0) ;
        int i = 0 , j = 1 ;
        for(int idx=0 ; idx<n ; idx++){
        
            if(nums[idx] >= 0){
                ans[i] = nums[idx] ;
                i += 2 ;
            }
            else{
                ans[j] = nums[idx] ;
                j += 2 ;
            }
        }

        return ans ;
    }
};


// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // This code will work when the condition 2 is not given in question or we can say that this code voilate the condition 2 
        int n = nums.size() ;
        int i=0 , j = 1 ; // i point to +ve value and j point to -ve value

        while(i < n && j < n){
            // case 1 -> Both pointer pointing to incorrect value then swap them
            if(nums[i] < 0 && nums[j] >=0){
                swap(nums[i], nums[j]) ;
                i += 2, j+= 2;
            }
            else{
                // case 2 -> one of them is pointing to correct value then just move the pointer
                if(nums[i] >= 0) i += 2 ;
                else j += 2 ;
            }
        }
    }
};









// Approch -> 1: Using two pointer approch
// T.C. = O(N)
// S.C. = O(N + N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans ;
        int i = 0, j = 0 ;

       while(i<n && nums[i] < 0) i++ ; 
       ans.push_back(nums[i]) ; 
       i++ ;
       while(i<n && nums[i] < 0) i++ ; 
       while(j<n && nums[j] >= 0) j++ ;

       // i points to the positive integers
       // j points to the negative integers

       while(i<n && j<n){
           int temp = ans.back() ;

           if(temp >= 0){
               ans.push_back(nums[j]) ;
               j++ ;
               while(j<n && nums[j] >= 0) j++ ;
           }
           else{
               ans.push_back(nums[i]) ;
               i++ ;
               while(i<n && nums[i] < 0) i++ ; 
           }
       }

       if(i==n) ans.push_back(nums[j]) ;
       else ans.push_back(nums[i]) ;

        return ans ;
    }
};