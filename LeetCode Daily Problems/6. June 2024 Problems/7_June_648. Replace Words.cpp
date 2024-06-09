https://leetcode.com/problems/replace-words/

class Solution {
public:
    struct trieNode{
        trieNode* children[26];
        bool isEnd;
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode -> isEnd = false;

        for(int i = 0; i < 26; i++){
            newNode -> children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;

    void insert(string word) {
        trieNode* crawler = root;

        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(crawler -> children[idx] == NULL){
                crawler -> children[idx] = getNode();
            }

            crawler = crawler -> children[idx];
        }

        crawler -> isEnd = true;
    }

    string search(string word){
        trieNode* crawler = root;

        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(crawler -> children[idx] == NULL){
                return word;
            }

            crawler = crawler -> children[idx];
            
            if(crawler -> isEnd){
                return word.substr(0, i+1);
            }
        }

        return word;
    }


    string replaceWords(vector<string>& dictionary, string sentence) {
        root = getNode();

        for(string& word: dictionary){
            insert(word);
        }

        stringstream ss(sentence);
        string word;
        string result;
        while(getline(ss, word, ' ')){
            result += search(word) + " ";
        }

        result.pop_back();

        return result;
    }
};




class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> mp;
        string new_str = "";

        for(int i = 0; i < dictionary.size(); i++){
            mp[dictionary[i]] = i;
        }

        int i = 0;
        int n = sentence.size();

        while(i < n){
            string str = "";
            string replaced = "";
            int st_idx = i;
            bool flag = true;

            while(i < n && sentence[i] != ' '){
                str += sentence[i];

                if(mp.find(str) != mp.end() && flag){
                    replaced = dictionary[mp[str]];
                    flag = false;
                }
                i++;
            }

            if(!flag){
                new_str += replaced;
                //cout << st_idx << " " << i << endl;
            }
            else{
                new_str += str;
            }

            i++;
            if(i < n){
                new_str += ' ';
            }
        }

        return new_str;
    }
};
