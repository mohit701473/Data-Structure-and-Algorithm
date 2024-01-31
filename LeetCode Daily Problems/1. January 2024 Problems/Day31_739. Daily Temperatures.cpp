https://leetcode.com/problems/daily-temperatures/description/

// Approch -> Max Satck
// T.C. = O(N) + O(N)
// S.C. = O(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size() ;
        vector<int> ans(n, 0) ;
        stack<int> st ;
        st.push(n-1) ;
        ans[n-1] = 0 ;

        for(int i=n-2 ; i>=0 ; i--){

            if(temperatures[i] < temperatures[st.top()]){
                ans[i] = st.top() - i ;
            }
            else{
                // for complete outer loop this while loop will run only N times
                while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                    st.pop() ;
                }

                if(st.empty()){
                    ans[i] = 0 ;
                    
                }
                else{
                    ans[i] = st.top() - i ;
                }
            }

            st.push(i) ;
        }

        return ans ;
    }
};