// LeetCode -> 713. Subarray Product Less Than K
https://leetcode.com/problems/subarray-product-less-than-k/description/

/*
Similar Problems -> 
*/

// T.C. = O(2n)
// S.C. = O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0 ;

        int n = nums.size(), i=0, j=0 ;
        int product = 1, cnt = 0 ; 

        while(j < n){
            product *= nums[j] ;

            while(product >= k){
                product /= nums[i] ;
                i++ ;
            }

            cnt += (j - i + 1) ; // (j - i +1) it means numbers of subarray ending at j
            j++ ;
        }

        return cnt ;


// ---------------------------------------------------------------------------------------------------------------------------------

        /*
        if(k == 0 || k == 1)
            return 0 ;

        int n = nums.size(), i=0, j=0 ;
        int product = 1, cnt = 0 ;

        while(i<n && j<n){
            product *= nums[j] ;
            

            if(product < k){
                cnt += (j - i + 1) ; // (j - i +1) it means numbers of subarray ending at j
            }
            else{
                while(product >= k && i <= j){
                    product /= nums[i] ;
                    i++ ;
                }

                if(product != 1){
                    cnt += (j - i + 1) ;
                }
            }

            j++ ;
        }

        return cnt ;

        */


// ---------------------------------------------------------------------------------------------------------------------------------


        /*
        if(k == 0 || k == 1)
            return 0 ;

        int n = nums.size(), i=0, j=0 ;
        int product = 1, cnt = 0 ;

        while(i<n && j<n){
            product *= nums[j] ;
            j++ ;

            if(product < k){
                cnt += (j - i) ;
            }
            else{
                while(product >= k && i < j){
                    product /= nums[i] ;
                    i++ ;
                }

                if(product != 1){
                    cnt += (j - i) ;
                }
            }
        }

        return cnt ;
        */
    }
};