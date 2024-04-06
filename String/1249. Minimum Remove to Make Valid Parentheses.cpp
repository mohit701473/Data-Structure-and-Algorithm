// LeetCode -> 1249. Minimum Remove to Make Valid Parentheses
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/



// Approch -> String + Vector / Stack
// T.C. = O(n + n) => O(n)
// S.C. = O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        // Step 1 : Iterate from start
        int count=0; 
        for(int i=0;i<n;++i){
            if(s[i]=='('){ // for open bracket
                ++count;
            }
            else if(s[i]==')'){ // for close bracket
                if(count==0){  // if no. of close brackets > no. of open brackets
                    s[i]='#';
                }
                else{
                    // if matching parentheses found decrease count
                    --count;
                }
            }
        }
        
        // Step 2 : Iterate from end
        count=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')'){ // for close bracket
                ++count;
            }
            else if(s[i]=='('){ // for open bracket
                if(count==0){ // if no. of open brackets > no. of close brackets
                    s[i]='#';
                }
                else{
                    // if matching parentheses found decrease count
                    --count;
                }
            }
        }
        
        // Step 3 : Create "ans" by ignoring the special characters '#'
        string ans="";
        for(int i=0;i<n;++i){
            if(s[i]!='#'){ 
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------------------


// Approch -> String + Vector / Stack
// T.C. = O(n + n) => O(n)
// S.C. = O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size() ;
        vector<int> removeIdx ;
        int openCnt = 0 ;
        
        for(int i=0 ; i<n ; i++){
            char ch = s[i] ;
            if(ch == '('){
                openCnt++ ;
                removeIdx.push_back(i) ;
            }
            else if(ch == ')'){
                if(openCnt > 0){
                    openCnt-- ;
                    removeIdx.pop_back() ;
                }
                else{
                    removeIdx.push_back(i) ;
                }
            }
        }

        string str = "" ;
        int j = 0 ;
        for(int i=0 ; i<n ; i++){
            if(j < removeIdx.size() && i == removeIdx[j]){
                j++ ;
                continue ;
            }

            str += s[i] ;
        }

        return str ;
    }
};