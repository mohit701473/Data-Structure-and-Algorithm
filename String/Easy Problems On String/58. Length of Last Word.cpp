// LeetCode -> 58. Length of Last Word
https://leetcode.com/problems/length-of-last-word/description/


// T.C. = O(n)
// S.C. = O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0 ; 
        int n = s.size() ;
        int i = n-1 ;

        while(s[i] == ' ') {
            i-- ;
        }

        while(i >=0 && s[i] != ' '){
            i-- ;
            len++ ;
        }

        return len ;
    }
};