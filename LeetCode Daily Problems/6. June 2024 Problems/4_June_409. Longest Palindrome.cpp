https://leetcode.com/problems/longest-palindrome/description/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int maxLen = 0, oddCnt = 0;

        for(auto &ch: s){
            freq[ch]++;
        }

        for(auto &it: freq){
            if(it.second & 1){
                oddCnt++;
                maxLen += it.second - 1;
            }
            else{
                maxLen += it.second;
            }
        }

        if(oddCnt){
            maxLen += 1;
        }

        return maxLen;
    }
};