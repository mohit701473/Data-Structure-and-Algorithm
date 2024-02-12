https://leetcode.com/problems/majority-element/description/


// Approch -> 4: Moore's Voting Algorithm
// T.C. = O(2N)
// S.C. = O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size() ;
        int ans = nums[0] ;
        int count = 1 ; 

        // By this for loop the ans might be majority element
        for(int i=1 ; i<n ; i++){
            if(nums[i] == ans){
                count++ ;
            }else{
                count-- ;
            }

            if(count == 0){
                ans = nums[i] ;
                count = 1 ;
            }
        }

        count = 0 ;
        // By this for loop the we can ansure that if count > (n/2 ) then ans will store majority element
        for(int i=0 ; i<n ; i++){
            if(nums[i] == ans)
                count++ ;
        }

        if(count > n/2)
            return ans ;

        return -1 ;
    }
};



// Approch -> 3: Using Sorting
// T.C. = O(NLog(N)) + O(N)
// S.C. = O(1) ;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int ans = -1 ;
        sort(nums.begin(), nums.end()) ;

        for(int i=0 ; i<n ; i++){
            if(nums[i] == nums[i+n/2]){
                ans = nums[i] ;
                break ;
            }
        }

        return ans ;
    }
};


// Approch -> 2: Using Hash Table
// T.C. = O(N)
// S.C. = O(N) ;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size(), ans ;
        unordered_map<int, int> freq ;

        for(auto it: nums){
            freq[it]++ ;
        }

        for(auto it: freq){
            if(it.second > n/2){
                ans = it.first ;
                break ;
            }
        }

        return ans ;

    }
};




// Approch -> 1: Brute Force Approch
// T.C. = O(N^2)
// S.C. = O(1) ;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans = INT_MIN ;
        int n = nums.size() ;

        for(int i=0 ; i<n ; i++){
            int ele = nums[i] ;
            int count = 1 ;

            for(int j=i+1 ; j<n ; j++){
                if(nums[j] == ele)
                    count++ ;
            }

            if(count > n/2){
                ans = ele ;
                break ;
            }
        }

        return ans ;
    }
};