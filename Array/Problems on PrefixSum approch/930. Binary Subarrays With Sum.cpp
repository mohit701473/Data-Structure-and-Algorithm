// LeetCode -> 930. Binary Subarrays With Sum
https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:

    int atMost(vector<int>& nums, int goal)
    {
        int i = 0, j = 0, ans = 0, sum = 0 ;

        if (goal < 0)
            return 0 ;

        for(j = 0 ; j < nums.size() ; j++)
        {
            sum += nums[j] ;

            while(sum>goal)
            {
                sum -= nums[i] ;
                i++ ;
            }
            // window_end-window_start+1 => This means the number of the subarrays whose sum is
            // atmost goal   
            ans += j - i + 1 ;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Approch -> Sliding Window
        // T.C. = O(n)
        // S.C. = O(1)
        return atMost(nums,goal)-atMost(nums,goal-1);
        

        // ---------------------------------------------------------------------------------

        

        // Approch -> Prefix Sum
        // T.C. = O(n)
        // S.C. = O(2n)
        int n = nums.size() ;
        int ans = 0 ;
        int sum = 0 ;
        unordered_map<int, int> mp ; // key -> sum and value -> number of occurance ;
        mp[0]++ ;

        for(int i=0 ; i<n ; i++){
            sum += nums[i] ;
            int y = sum - goal ;
            if(mp.find(y) != mp.end()){
                ans += mp[y] ;
            }
            mp[sum]++ ;
        }

        return ans ; 

        

        // ---------------------------------------------------------------------------------

        
        // Approch -> generating all teh subsarrays with computing the sum of the subarray and 
        // check if sum ie equal to goal then that subarray can contribute in your answer

        // T.C. = O(N^2)
        // S.C. = O(1)
        int n = nums.size() ;
        int ans = 0 ; // this will store the total number of subarrays whose sum equal to goal

        
        for(int i=0 ; i<n ; i++){
            int sum = 0 ;
            // generating the subarrays + calculating the sum of the subarray
            for(int j=i ; j<n ; j++){
                sum += nums[j] ;
                if(sum == goal){
                    ans++ ;
                }
            }
        }

        return ans ;

        

        // ------------------------------------------------------------------------------------


        
        // Approch -> generating all the subsarrays and computing the sum of the every subarray and 
        // check if sum ie equal to goal then that subarray can contribute in your answer

        // T.C. = O(N^3)
        // S.C. = O(1)
        int n = nums.size() ;
        int ans = 0 ; // this will store the total number of subarrays whose sum equal to goal

        // generating the subarrays 
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                int sum = 0 ;
                // calculating the sum of the subaray
                for(int k=i ; k<=j ; k++){
                    sum += nums[k] ;
                }

                if(sum == goal){
                    ans++ ;
                }
            }
        }

        return ans ;
        
    }
};