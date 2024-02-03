https://leetcode.com/problems/partition-array-for-maximum-sum/description/


// Approch 1 -> Recursion
// T.C. = eponential / Factroial
// S.C. = O()
class Solution {

    int solve(int i, vector<int> &arr){
        if(i >= n)
            return 0 ;

        int maxVal = 0, ans = 0 ;

        for(int j=i ; j < min(n, i+K) ; j++){
            maxVal = max(maxVal, arr[j]) ;
            ans = max(ans, (maxVal * (j-i+1) + solve(j+1, arr))) ;
        }

        return ans ;
    }

public:
    int n, K ;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size() ;
        K = k  ;
        return solve(0, arr) ;
    }
};



// Approch 2 -> Memoization
// T.C. = O(N * k)
// S.C. = O(N)
class Solution {

    int solve(int i, vector<int> &arr){
        if(i >= n)
            return 0 ;

        if(dp[i] != -1)
            return dp[i] ;

        int maxVal = 0, ans = 0 ;

        for(int j=i ; j < min(n, i+K) ; j++){
            maxVal = max(maxVal, arr[j]) ;
            ans = max(ans, (maxVal * (j-i+1) + solve(j+1, arr))) ;
        }

        return dp[i] = ans ;
    }

public:
    int n, K ;
    vector<int> dp ;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size() ;
        K = k  ;
        dp = vector<int> (n,-1) ;
        return solve(0, arr) ;
    }
};



// Approch 3 -> Bottom Up
// T.C. = O(N * k)
// S.C. = O(N)
class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;
        vector<int> dp(n+1, 0) ;

        for(int i=n-1 ; i>=0 ; i--){
            int maxVal = 0 ;
            for(int j=i ; j < min(n, i+k) ; j++){
                maxVal = max(maxVal, arr[j]) ;
                dp[i] = max(dp[i], (maxVal * (j-i+1) + dp[j+1])) ;
            }
        }

        return dp[0] ;
    }
};



// Approch 4 -> Space Optimization
// T.C. = O(N * k)
// S.C. = O(k)
class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;
        vector<int> dp(k+1, 0) ;

        for(int i=n-1 ; i>=0 ; i--){
            int maxVal = 0, ans = 0 ;
            for(int j=i ; j < min(n, i+k) ; j++){
                maxVal = max(maxVal, arr[j]) ;

                //dp[i%k] = max(dp[i], (maxVal * (j-i+1) + dp[(j+1) % k])) ; => Wrong
                ans = max(ans, (maxVal * (j-i+1) + dp[(j+1) % k])) ;
            }

            dp[i%k] = ans ;
        }

        return dp[0] ;
    }
};