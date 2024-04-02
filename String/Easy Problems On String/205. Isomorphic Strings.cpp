// LeetCode -> 205. Isomorphic Strings
https://leetcode.com/problems/isomorphic-strings/description/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapSToT ;
        unordered_map<char, char> mapTToS ;
        for(int i=0 ; i<s.size() ; i++){
            if( (mapSToT.find(s[i]) != mapSToT.end() && mapSToT[s[i]] != t[i]) || ( mapTToS.find(t[i]) != mapTToS.end() && mapTToS[t[i]] != s[i] ) ){
                
                return false ;
            }
            mapSToT[s[i]] = t[i] ;
            mapTToS[t[i]] = s[i] ;
        }
        return true ;
    }
};