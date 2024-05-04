// LeetCode -> 2000. Reverse Prefix of Word
https://leetcode.com/problems/reverse-prefix-of-word/description/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int ch_idx = -1;

        for(int i = 0; i < n; i++){
            if(word[i] == ch){
                ch_idx = i;
                break;
            }
        }

        if(ch_idx == -1) return word;

        // reverse 
        int i = 0;
        int j = ch_idx;
        while(i < j){
            swap(word[i], word[j]);
            i++, j--;
        }

        return word;
    }
};