https://leetcode.com/problems/perfect-squares/description/

// Approch -> Math approch 
// T.C. = O(sqrt(n))
// S.C. = O(1)
class Solution {
public:
    int numSquares(int n) {
        int m = n ;
        int sqrtVal = (int) sqrt(n) ;

        if(sqrtVal * sqrtVal == n) return 1 ;

        while(n % 4 == 0) n = n/4 ;
        
        if(n % 8 == 7)
            return 4 ;
        
        n = m ;

        for(int i=1 ; i * i <= n ; i++){
            int sqrA = i * i ;
            int eleB = (int)sqrt(n - sqrA) ;

            if( eleB * eleB == (n - sqrA) )
                return 2 ;
        }

        return 3 ;
    }
};




// Approch 1 -> DP
// T.C. = O((sqrt(n))^n)
// S.C. = O(n)
class Solution {

    int solve(int n){
        if(n == 0)
            return 0 ;

        int mini = INT_MAX ;
        for(int i=1 ; i*i <= n ; i++){
            mini = min(mini, 1 + solve(n - (i*i))) ;
        }

        return mini ;
    }

public:
    int numSquares(int n) {
        return solve(n) ;
    }
};


// Approch 1 -> DP Memoization
// T.C. = O(n * sqrt(n))
// S.C. = O(n)
class Solution {

    int solve(int n, vector<int> &dp){
        if(n == 0)
            return 0 ;

        if(dp[n] != -1)
            return dp[n] ;

        int mini = INT_MAX ;
        for(int i=1 ; i*i <= n ; i++){
            mini = min(mini, 1 + solve(n - (i*i), dp)) ;
        }

        return dp[n] = mini ;
    }

public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1) ;
        return solve(n, dp) ;
    }
};



// Approch 1 -> DP Tabulation
// T.C. = O(n * sqrt(n))
// S.C. = O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0) ;

        for(int i=1 ; i<=n ; i++){
            dp[i] = i ; //put all 1s squares
            for(int j=1 ; j*j <= i ; j++){
                int sqr = j*j ;
                dp[i] = min(dp[i], 1 + dp[i-sqr]) ;
            }
        }

        return dp[n] ;
    }
};




// Approch 1 -> DP
// T.C. = O(n * k)
// S.C. = O(n)
class Solution {

    bool isPerfectSquare(double num){
        double root = sqrt(num) ;
        return (ceil((double)sqrt(num)) == floor((double)sqrt(num))) ;
    }
    
    int solve(int n){
        if(n == 0)
            return 0 ;
        
        if(n < 0) return INT_MAX ;

        if(dp[n] != -1)
            return dp[n] ;

        int mini = INT_MAX ;
        for(auto &sr: perfectSqr){
            // if(n - sr < 0){
            //     break ;
            // }
            long long int ans = 1 + (long long)solve(n - sr) ;
            mini = min((long long)mini, ans) ;
        }

        return dp[n] = mini ;
    }

public:
    vector<int> perfectSqr ;
    vector<int> dp ;
    int numSquares(int n) {
        // first store the prefect square till n ;
        for(int i=1 ; i<=n ; i++){
            if(isPerfectSquare(i)){
                perfectSqr.push_back(i) ;
            }
        }
        dp = vector<int> (n+1, -1) ;
        return solve(n) ;
    }
};