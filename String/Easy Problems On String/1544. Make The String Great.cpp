// LeetCode -> 1544. Make The String Great
https://leetcode.com/problems/make-the-string-great/description/


// Approch -> String 
// T.C. = O(n)
// S.C. = O(1)
class Solution {
public:
    string makeGood(string s) {
        string str= "" ;
        int n = s.size(), i = 0 ;

        while(i < n){
            str.push_back(s[i]) ;
            i++ ;

            while(!str.empty() && i < n && ( (str.back() - 'a' == s[i] - 'A') || (str.back() - 'A' == s[i] - 'a') )){
                str.pop_back() ;
                i++ ;
            }
        }

        return str ;
    }
};

// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------

// Approch -> String + Stack
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    string makeGood(string s) {
        stack<char> st ;
        int n = s.size(), i = 0 ;

        while(i < n){
            st.push(s[i]) ;
            i++ ;

            while(!st.empty() && i < n && ( (st.top() - 'a' == s[i] - 'A') || (st.top() - 'A' == s[i] - 'a') )){
                st.pop() ;
                i++ ;
            }
        }

        string str= "" ;
        while(!st.empty()){
            str += st.top() ;
            st.pop() ;
        }

        reverse(str.begin(), str.end()) ;

        return str ;
    }
};