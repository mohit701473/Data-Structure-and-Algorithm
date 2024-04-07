// LeetCode -> 678. Valid Parenthesis String
https://leetcode.com/problems/valid-parenthesis-string/description/



// Approch -> String + Stack
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size() ;
        int starCnt = 0 ;
        stack<int> open ;
        stack<int> star ;

        for(int i=0 ; i<n ; i++){
            char ch = s[i] ;

            if(ch == '*'){
                star.push(i) ;
            }
            else if(ch == '('){
                open.push(i) ;
            }
            else if(ch == ')'){
                if(!open.empty()){
                    open.pop() ;
                }
                else if(!star.empty()){
                    star.pop() ;
                }
                else return false ;
            }
        }

        while(!star.empty() && !open.empty()){
            if(star.top() < open.top()){
                return false ;
            }

            star.pop() ;
            open.pop() ;
        }

        if(!open.empty()){
            return false ;
        }

        return true ;
    }
};



// DP
// T.C. Recursicve Solution = O(3 ^ n) -> 3 => No. of options
// Approch -> Recursion + Memoization
// T.C. = O(n * n)
// S.C. = O(n * n) and Recursive Stack Space is O(n)

class Solution {
public:

    int dp[101][101] ;

    bool solve(int idx, int openCnt, string &s){
        if(idx >= s.size()){
            return openCnt == 0 ;
        }

        if(dp[idx][openCnt] != -1){
            return dp[idx][openCnt] ;
        }

        bool isValid = false ;
        if(s[idx] == '*'){
            isValid |= solve(idx+1, openCnt+1, s) ; // * == '('

            isValid |= solve(idx+1, openCnt, s) ; // * == ""

            if(openCnt > 0){
                isValid |= solve(idx+1, openCnt - 1, s) ; // * == ')'
            }
        }
        else if(s[idx] == '('){
            isValid |= solve(idx+1, openCnt+1, s) ;
        }
        else if(openCnt > 0){
            isValid |= solve(idx+1, openCnt - 1, s) ;
        }

        return dp[idx][openCnt] = isValid ;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp)) ;
        return solve(0, 0, s) ;
    }
};





// Approch -> Bottom Up
// T.C. = O(n * n)
// S.C. = O(n * n)
class Solution {
public:

    bool checkValidString(string s) {
        int n = s.size() ;
        vector<vector<bool>> dp(n+1, vector<bool> (n+1, false)) ;

        dp[n][0] = true ; // dp[n][0] measn you are at the n-th idx i.e out of string and no of open parenthesis
                          // is 0 i.e. string is "" i.e it is valid that why it is true;
        // dp[n][1] = false, dp[n][2] = false, ..... dp[n][n] = false ;
        // for idx = n and openCnt = 1, 2, 3... n i.e. you are the n-th idx and you have 1, 2, 3 or n open parenthesis
        // i.e. it is not a valid string that is why it is false ;


        for(int idx = n-1 ; idx >=0 ; idx--){
            for(int openCnt = 0 ; openCnt <= n ; openCnt ++){

                bool isValid = false ;
                if(s[idx] == '*'){
                    isValid |= dp[idx+1][openCnt+1] ; // solve(idx+1, openCnt+1, s) ; // * == '('

                    isValid |= dp[idx+1][openCnt] ; // solve(idx+1, openCnt, s) ; // * == ""

                    if(openCnt > 0){
                        isValid |= dp[idx+1][openCnt-1] ; // solve(idx+1, openCnt - 1, s) ; // * == ')'
                    }
                }
                else if(s[idx] == '('){
                    isValid |= dp[idx+1][openCnt+1] ; // solve(idx+1, openCnt+1, s)
                }
                else if(openCnt > 0){
                    isValid |= dp[idx+1][openCnt-1] ; // solve(idx+1, openCnt - 1, s)
                }

                dp[idx][openCnt] = isValid ;
            }   
        }

        return dp[0][0] ;
    }
};




// Approch -> Greedy
// Approch -> Left to Right validate and Right to Left Validate
// T.C. = O(2n)
// S.C. = O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size() ;
        int openCnt = 0 ;
        int closeCnt = 0 ;

        // left to right and '*' = '('
        for(int i=0 ; i<n ; i++){
            if(s[i] == '(' || s[i] == '*'){
                openCnt++ ;
            }
            else{
                openCnt-- ;
            }

            if(openCnt < 0)
                return false ;
        }

        // right to left and '*' = ')'
        for(int i=n-1 ; i>=0 ; i--){
            if(s[i] == ')' || s[i] == '*'){
                closeCnt++ ;
            }
            else{
                closeCnt-- ;
            }

            if(closeCnt < 0)
                return false ;
        }

        return true ;
    }
};