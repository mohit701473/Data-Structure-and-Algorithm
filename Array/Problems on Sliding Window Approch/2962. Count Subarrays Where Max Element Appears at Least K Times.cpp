// LeetCode -> 2962. Count Subarrays Where Max Element Appears at Least K Times
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        // Intution -> store the indices of the maxEle and when your maxIndices array size == k i.e 
        // your subarray have at least k maxEle then find the first idx of maxEle i.e
        // maxIndices[size-k] is your lastIdx then from the lastIdx to to till 0-th idx all subarray
        // have at lest k maxEle then add lastIdx+1 into result and go on

        // T.C. = O(n)
        // S.C. = O(n)
        int maxEle = INT_MIN ;
        
        for(auto &it: nums){
            maxEle = max(maxEle, it) ;
        }

        int n = nums.size() ;
        long long res = 0 ;
        vector<int> maxIndices ;

        for(int i=0 ; i<n ; i++){

            if(nums[i] == maxEle){
                maxIndices.push_back(i) ;
            }

            int size = maxIndices.size() ;

            if(size >= k){
                int last_idx = maxIndices[size-k] ;
                res += last_idx + 1 ;
            }
        }

        return res ;



// -----------------------------------------------------------------------------------------------------------------


        /*
        // Approch -> Sliding Window
        // Intution -> Agr window m maxEle ka cnt >= K i.e. it is a good subarray then add this subarray into result
        // now you have (n - j) subarray also which are good subarray becaus if from i to j maxEle ka cnt >= K
        // then if we take j+1, j+2, j+3.... n-1 idx all these subarray have at least cnt >= K bcz i to j we have cnt >= k
        // and whenever cnt >= K then we increase the i for shrinking the window till cnt >= K and if cnt < K then we increase
        // j till cnt is not equal to K

        // T.C. = O(3n)
        // S.C. = O(1)


        int maxEle = INT_MIN ;
        
        for(auto &it: nums){
            maxEle = max(maxEle, it) ;
        }

        int i = 0, j = 0, freqCnt = 0 ;
        int n = nums.size() ;
        long long res = 0 ;

        while(j < n){

            if(nums[j] == maxEle){
                freqCnt++ ;
            }

            while(freqCnt >= k){

                res += n - j ; // by n- j we are adding all j+1, j+2 ... n-1 subarray

                if(nums[i] == maxEle){
                    freqCnt-- ;
                }

                i++ ;
            }

            j++ ;
        }

        return res ;

        */



// -----------------------------------------------------------------------------------------------------------------


        /*
        // Approch -> Sliding Window 
        // Intution -> Count the number of the subarray where max element appears at most K time not equal to K
        // then after subtract this cnt to the total subarray cnt

        // T.C. = O(3n)
        // S.C. = O(1)


        int maxEle = INT_MIN ;
        int freqCnt = 0, i = 0, j = 0 ;
        long long n = nums.size() ;
        long long cnt = 0 ;

        for(auto &it: nums){
            maxEle = max(maxEle, it) ;
        }

        while(j < n){
            if(nums[j] == maxEle){
                freqCnt++ ;
            }

            while(freqCnt >= k){
                if(nums[i] == maxEle){
                    freqCnt-- ;
                }
                i++ ;
            }

            cnt += (j-i+1) ;
            j++ ;
        }

        long long totalSubarray = (n * (n+1)) / 2 ;

        return totalSubarray - cnt ;

        */
    }
};