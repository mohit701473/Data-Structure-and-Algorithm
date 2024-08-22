#include <bits/stdc++.h> 
class TrieNode {
public:
    // TrieNode* children[26];
    vector<TrieNode*> children;
    int cnt;
    int endCnt;

    TrieNode() {
        endCnt = 0;
        cnt = 0;
        // children = vector<TrieNode> (26);
        for (int i = 0; i < 26; i++)
            children.push_back(NULL); 
    }
};

class Trie{
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr -> children[word[i] - 'a'] == NULL)
                curr -> children[word[i] - 'a'] = new TrieNode;
            curr = curr -> children[word[i] - 'a'];
            curr -> cnt++;
        }

        curr -> endCnt++;
    }

    int countWordsEqualTo(string &word){
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr -> children[word[i] - 'a'] == NULL)
                return 0;
            curr = curr -> children[word[i] - 'a'];
        }

        return curr -> endCnt;
    }

    int countWordsStartingWith(string &word){
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr -> children[word[i] - 'a'] == NULL)
                return 0;
            curr = curr -> children[word[i] - 'a'];
        }

        return curr -> cnt;
    }

    void erase(string &word){
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            curr = curr -> children[word[i] - 'a'];
            curr -> cnt--;
        }

        curr -> endCnt--;
    }
};
