https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/



// T.C. = O(n^2)
// S.C. = O(1)
class Solution {

    bool isPalindrome(string &str){
        int i = 0 , j = str.size() - 1 ;
        while(i < j){
            if(str[i] != str[j]){
                return false ;
            }
            i++, j-- ;
        }

        return true ;
    }

public:
    string firstPalindrome(vector<string>& words) {
        
        for(auto &str: words){
            if(isPalindrome(str)){
                return str ;
            }
        }

        return "" ;
    }
};