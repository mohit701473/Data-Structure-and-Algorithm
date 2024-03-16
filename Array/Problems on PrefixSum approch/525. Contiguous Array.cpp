// LeetCode -> 525. Contiguous Array
https://leetcode.com/problems/contiguous-array/description/



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Intution -> hash Map + PrefixSum
        // T.C. = O(n)
        // S.C. = O(n)
        int maxLen = 0 ;
        // map will store (cumulative sum , idx)
        unordered_map<int, int> mp ; 
        int i = 0 ;
        int currSum = 0 ;
        mp[0] = -1 ;

        while(i < nums.size()){
            currSum += nums[i] ;
            // replace zero with -1 
            if(nums[i] == 0) currSum += -1 ; 

            // check kro ki past m kabhi currSum mila h ya nhi
            // mila h to obvios that maxLen ko update kr do 
            if(mp.find(currSum) != mp.end()){
                maxLen = max(maxLen , i-mp[currSum]) ;
            }
            else{ // nahi mila to currSum ko index ke sath map me dal do
                mp[currSum] = i ;
            }

            i++ ;
        }

        return maxLen ;


// --------------------------------------------------------------------------------------------


        
        
        // Intution -> generating all the subarrays and checking for the given condition
        // T.C. = O(n^2)
        // S.C. = O(1)
        int maxLen = 0 ;
        int n = nums.size() ;

        // here you are generating all the subarrays 
        for(int i=0 ; i<n ; i++){

            int zeroCnt = 0, oneCnt = 0 ;

            for(int j=0 ; j<n ; j++){
                if(nums[j] == 1){
                    oneCnt++ ;
                }
                else{
                    zeroCnt++ ;
                }

                if(zeroCnt == oneCnt){
                    //cout << zeroCnt << endl ;
                    maxLen = max(maxLen, j-i+1) ;
                }
            }
            
        }

        return maxLen ;
        

// --------------------------------------------------------------------------------------------

        
        // Intution -> generating all the subarrays and checking for the given condition
        // T.C. = O(n^3)
        // S.C. = O(1)
        int maxLen = 0 ;
        int n = nums.size() ;

        // here you are generating all the subarrays 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                // from i to j is a subarray
                // now check for condition 
                int zeroCnt = 0, oneCnt = 0 ;
                for(int k=i ; k<=j ; k++){
                    if(nums[k] == 1){
                        oneCnt++ ;
                    }
                    else{
                        zeroCnt++ ;
                    }
                }
                if(zeroCnt == oneCnt){
                    //cout << zeroCnt << endl ;
                    maxLen = max(maxLen, j-i+1) ;
                }
            }
        }

        return maxLen ;
        
    }
};