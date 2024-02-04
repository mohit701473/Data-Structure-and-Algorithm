https://leetcode.com/problems/minimum-window-substring/description/


// T.C. = O(N + M)
// S.C. = O(1)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmp ;
        for(auto ch: t) tmp[ch]++ ;

        int i=0, j=0, counter=t.size(), minStart=0, minLen=INT_MAX ;
        int n = s.size() ;

        while(j < n){
            if(tmp[s[j]] > 0){
                counter-- ;
            }
            tmp[s[j]]-- ;
            j++ ;

            while(counter == 0){
                if(j-i < minLen){
                    minStart = i ;
                    minLen = j-i ;
                }

                tmp[s[i]]++ ;
                if(tmp[s[i]] > 0){
                    counter++ ;
                }
                i++ ;
            }
        }

        return (minLen != INT_MAX ? s.substr(minStart, minLen) : "") ;
    }
};