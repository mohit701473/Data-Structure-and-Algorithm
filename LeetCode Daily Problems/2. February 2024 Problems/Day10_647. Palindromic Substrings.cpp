https://leetcode.com/problems/palindromic-substrings/description/


// T.C. = O(n^3)
// S.C. = O(1)
class Solution {

    bool isPalindrome(string &str){
        int i=0, j = str.size() - 1 ;
        while(i < j){
            if(str[i] != str[j])
                return false ;

            i++, j-- ;
        }

        return true ;
    }

public:
    int countSubstrings(string s) {
        int cnt = 0 ;
        int n = s.size() ;

        for(int i=0 ; i<n ; i++){
            string str = "" ;
            for(int j=i ; j<n ; j++){
                str += s[j] ;
                if(isPalindrome(str)) cnt ++ ;
            }
        }

        return cnt ;
    }
};


// Approch -> 2: Recursion
// T.C. = O(n^3)
// S.C. = O(n)
class Solution {

    int isPalindromeRecursion(int i, int j, string &s){
        if(i >= j)
            return 1 ;

        return (s[i] == s[j] ? isPalindromeRecursion(i+1, j-1, s) : 0) ;
    }

public:
    int countSubstrings(string s) {
        int cnt = 0, len = s.length() ;
        for(int i=0 ; i<len ; i++){
            for(int j=i ; j<len ; j++){
                cnt += isPalindromeRecursion(i, j, s) ;
            }
        }

        return cnt ;
    }
};



// Approch -> 2: DP
// T.C. = O(n^2)
// S.C. = O(n^2) + O(n)
class Solution {

    int isPalindromeRecursion(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j)
            return 1 ;

        if(dp[i][j] == 1)
            return dp[i][j] ;

        return dp[i][j] = (s[i] == s[j] ? isPalindromeRecursion(i+1, j-1, s, dp) : 0) ;
    }

public:
    int countSubstrings(string s) {
        int cnt = 0, len = s.length() ;
        vector<vector<int>> dp(len, vector<int> (len, 0)) ;
        for(int i=0 ; i<len ; i++){
            for(int j=i ; j<len ; j++){
                cnt += isPalindromeRecursion(i, j, s, dp) ;
            }
        }

        return cnt ;
    }
};



// Approch -> 2: DP
// T.C. = O(n^2)
// S.C. = O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length() ;
        int cnt = 0 ;
        vector<vector<bool>> dp(len, vector<bool>(len, 0)) ;

        for(int g=0 ; g<len ; g++){
            for(int i=0, j=g; j < len ; i++, j++){
                if(g == 0){
                    dp[i][j] = true ;
                }
                else if(g == 1){
                    dp[i][j] = (s[i] == s[j]) ;
                }
                else {
                    if(s[i] == s[j] && dp[i+1][j-1] == true){
                        dp[i][j] = true ;
                    }
                    else{
                        dp[i][j] = false ;
                    }
                }

                if(dp[i][j]){
                    cnt++ ;
                }
            }
        }

        return cnt ;
    }
};