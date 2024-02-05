https://leetcode.com/problems/first-unique-character-in-a-string/description/

// Approch -> Hashing
// T.C. = O(n + 26)
// S.C. = O(26)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp ;
        for(int i=0 ; i<s.size() ; i++){
            char ch = s[i] ;
            mp[ch].first++ ;
            mp[ch].second = i ;
        }

        int ans = INT_MAX ;
        for(auto it: mp){
            if(it.second.first == 1){
                ans = min(ans, it.second.second) ;
            }
        }

        return (ans == INT_MAX ? -1 : ans) ;
    }
};