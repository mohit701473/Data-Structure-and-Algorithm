// LeetCode -> 1614. Maximum Nesting Depth of the Parentheses
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/



class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 , maxi = 0 ;
        for(int i=0 ; i<s.size() ; i++){
            int ch = s[i] ;
            if(ch == '('){
                maxi++ ;
                ans = max(ans, maxi) ;
            }else if(ch == ')') maxi-- ;
        }

        return ans ;
    }
};