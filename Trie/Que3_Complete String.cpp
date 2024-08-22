https://www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
class Trie {
public:
    Trie *children[26];
    bool isEnd;

    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

void insert(Trie* root, string &word) {
    Trie *curr = root;

    for (int i = 0; i < word.size(); i++) {
        if (curr -> children[word[i] - 'a'] == NULL)
            curr -> children[word[i] - 'a'] = new Trie();
        
        curr = curr -> children[word[i] - 'a'];
    }

    curr -> isEnd = true;
}

bool isCompleteString(Trie* root, string &word) {
    Trie *curr = root;

    for (int i = 0; i < word.size(); i++) {
        curr = curr -> children[word[i] - 'a'];

        if (curr -> isEnd == false)
            return false;
    }
    // cout << "-> " << word << endl;
    return true;
}

bool compareStrings(string &ans, string &str) {
    if (str.size() > ans.size())
        return true;
    else if (ans.size() > str.size())
        return false;

    return str < ans;
}

string completeString(int n, vector<string> &a){
    Trie *root = new Trie();
    string ans = "";

    for (auto &word: a)
        insert(root, word);

    for (auto &str: a) {
        if (isCompleteString(root, str) && compareStrings(ans, str))
            ans = str;
    }

    return ans == "" ? "None" : ans;
}