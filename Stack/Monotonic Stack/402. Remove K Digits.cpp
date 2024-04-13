// LeetCode -> 402. Remove K Digits
https://leetcode.com/problems/remove-k-digits/description/


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)
            return "0" ;

        string ans = "" ;

        for(int i=0 ; i<num.size() ; i++){
            
            while(ans.length() > 0 && ans.back() > num[i] && k > 0){
                ans.pop_back() ;
                k-- ;
            }

            if(ans.length() > 0 || num[i] != '0'){ // avoding the preceding zeros
                ans.push_back(num[i]) ;
            }
        }

        while(ans.length() > 0 && k > 0){
            ans.pop_back() ;
            k-- ;
        }

        if(ans == "")
            return "0" ;

        return ans ;
    }
};