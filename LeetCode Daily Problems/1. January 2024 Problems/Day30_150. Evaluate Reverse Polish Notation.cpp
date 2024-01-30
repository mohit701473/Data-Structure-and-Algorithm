https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// T.C. = o(N)
// S.C. = O(N)
class Solution {

    int result(int num1, int num2, string str){
        if(str == "+") return num1 + num2 ;
        if(str == "-") return num1 - num2 ;
        if(str == "*") return num1 * num2 ;
        return num1 / num2 ;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;
        
        for(int i=0 ; i<tokens.size() ; i++){
            string str = tokens[i] ;
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int num2 = (st.top()) ;
                st.pop() ;
                int num1 = (st.top()) ;
                st.pop() ;

                int ans = result(num1, num2, str) ;
                st.push(ans) ;
            }
            else{
                st.push(stoi(str)) ;
            }
        }

        return st.top() ;
    }

    
};