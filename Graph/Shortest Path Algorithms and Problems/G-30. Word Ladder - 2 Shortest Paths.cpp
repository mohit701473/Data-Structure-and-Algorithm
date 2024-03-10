// LeetCode -> 126. Word Ladder II
https://leetcode.com/problems/word-ladder-ii/description/



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s ;
        queue<vector<string>> q ;
        vector<vector<string>> ans ;
        unordered_set <string> tempSet ; 

        for(auto str: wordList){
            s.insert(str) ;
        }

        q.push({beginWord}) ;

        while(!q.empty()){
            int size = q.size() ;

            for(int i=0 ; i<size ; i++){
                vector<string> temp = q.front() ;
                string word = temp.back() ;
                q.pop() ;

                if(word == endWord){
                    ans.push_back(temp) ;
                }
                else{
                    // T.C. = word.length * 26 
                    for(int i=0 ; i<word.size() ; i++){
                        char ch = word[i] ;
                        for(int j=0 ; j<26 ; j++){
                            word[i] = char('a' + j) ;

                            if(s.find(word) != s.end()){
                                temp.push_back(word) ;
                                q.push(temp) ;
                                tempSet.insert(word) ;
                                temp.pop_back() ;
                            }
                        }
                        word[i] = ch ;
                    }
                }
            }

            // remove form set s 
            for(auto it: tempSet){
                s.erase(it) ;
            }
            tempSet.clear() ;
        }

        return ans ;
    }
};