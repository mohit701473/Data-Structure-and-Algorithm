#include<iostream>

using namespace std;

struct TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

void insert(TrieNode* head, string word) {
    TrieNode* curr = head;

    for(int i = 0; i < word.size(); i++) {
        char ch = word[i];
        if(curr -> children[ch-'a'] == NULL)
            curr -> children[ch-'a'] = new TrieNode();

        curr = curr -> children[ch-'a'];
    }

    curr -> isEnd = true;

    cout << "Word " << word << " is inserted into Trie" << endl;
}

bool search(TrieNode* head, string word) {
    TrieNode* curr = head;

    for(int i = 0; i < word.size(); i++) {
        char ch = word[i];

        if(curr -> children[ch-'a'] == NULL)
            return false;

        curr = curr -> children[ch-'a'];
    }

    return curr -> isEnd;
}

bool startsWith(TrieNode* head, string prefix) {
    TrieNode* curr = head;

    for(int i = 0; i < prefix.size(); i++) {
        char ch = prefix[i];

        if(curr -> children[ch-'a'] == NULL)
            return false;
        
        curr = curr -> children[ch-'a'];
    }

    return true;
}

int main() {
    TrieNode* head = new TrieNode();
    
    insert(head, "apple");
    insert(head, "apps");
    insert(head, "apxl");
    insert(head, "bac");
    insert(head, "bat");

    if(search(head, "apps"))
        cout << "apps founded" << endl;
    else cout << "apps not founded" << endl;

    if(search(head, "app"))
        cout << "app founded" << endl;
    else cout << "app not founded" << endl;

    if(startsWith(head, "app"))
        cout << "There are words which start with 'app'" << endl;
    else cout << "There are no words which start with 'app'" << endl;

    if(startsWith(head, "abxc"))
        cout << "There are words which start with 'abxc'" << endl;
    else cout << "There are no words which start with 'abxc'" << endl;

    return 0;
}