https://leetcode.com/problems/group-anagrams/description/

// T.C. = O(n^2 * k)
// S.C. = O(n*k)
class Solution {

    bool isAnagram(string &s, string &t){
        if(s.size() != t.size()) return false ;

        unordered_map<char, int> sMap, tMap ;
        for(int i=0 ; i<s.size() ; i++){
            sMap[s[i]]++ ;
            tMap[t[i]]++ ;
        }

        for(auto it: sMap){
            if((tMap.find(it.first) == tMap.end()) || (tMap[it.first] != it.second)) return false ;
        }

        return true ;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans ;
        int n = strs.size() ;
        vector<int> vis(n,0) ;

        for(int i=0 ; i<n ; i++){
            if(vis[i]) continue ;

            vector<string> temp ;
            temp.push_back(strs[i]) ;
            vis[i] = 1 ;

            for(int j=i+1; j<n ; j++){
                if(vis[j]) continue ;

                if(isAnagram(strs[i], strs[j])){
                    temp.push_back(strs[j]) ;
                    vis[j] = 1 ;
                }
            }

            ans.push_back(temp) ;
        }

        return ans ;
    }
};



// Approch -> 2
// T.C. = O(n * klog(k)) 
// S.C. = O(n * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp ;

        for(auto s: strs){
            string originalString = s ;
            sort(s.begin(), s.end()) ;
            mp[s].push_back(originalString) ;
        }

        vector<vector<string>> anagram ;
        for(auto it: mp){
            anagram.push_back(it.second) ;
        }

        return anagram ;
    }
};



// Approch -> 3
// T.C. = O(n * k) 
// S.C. = O(n * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp ;

        for(auto s: strs){
            string hashString = "" ;
            vector<int> freq(26, 0) ;
            for(auto ch: s) freq[ch - 'a']++ ;

            for(int i=0 ; i<26 ; i++){
                hashString.push_back(freq[i]) ;
                hashString.push_back('#') ;
            }

            mp[hashString].push_back(s) ;
        }

        vector<vector<string>> anagram ;
        for(auto it: mp){
            anagram.push_back(it.second) ;
        }

        return anagram ;
    }
};