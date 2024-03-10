// LeetCode -> 127. Word Ladder
https://leetcode.com/problems/word-ladder/description/


// T.C. = O(wordList.size() * word.length * 26 ) + O(wordList.size())
// S.C. = O(N + N)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s ;
        queue<pair<string, int>> q ;

        for(auto it: wordList){
            s.insert(it) ;
        }

        q.push({beginWord, 1}) ;

        // T.C. = wordList.size() * word.length * 26 
        while(!q.empty()){
            string word = q.front().first ;
            int level = q.front().second ;
            q.pop() ;

            // T.C. = word.length * 26 
            for(int i=0 ; i<word.size() ; i++){
                char ch = word[i] ;
                for(int j=0 ; j<26 ; j++){
                    word[i] = char('a' + j) ;

                    if(s.find(word) != s.end()){
                        if(word == endWord){
                            return level+1 ;
                        }
                        q.push({word, level+1}) ;
                        s.erase(word) ;
                    }
                }
                word[i] = ch ;
            }
        }

        return 0 ;
    }
};