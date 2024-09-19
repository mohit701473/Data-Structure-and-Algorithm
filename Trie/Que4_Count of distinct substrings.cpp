https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Run
class Trie {
public:
    Trie* children[26];
    bool isEnd;
    
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    
    Trie *isKeyExist(Trie *node, char key) {
        return node -> children[key - 'a'];
    }
    
    void insertKey(Trie *node, char key) {
        node -> children[key - 'a'] = new Trie();
    }
    
    Trie *getNextNode(Trie *node, char key) {
        return node -> children[key - 'a'];
    }
};

int countDistinctSubstring(string s)
{
    Trie *root = new Trie();
    int cnt = 0;
    
    for (int i = 0; i < s.size(); i++) {
        Trie* node = root;
        for (int j = i; j < s.size(); j++) {
            if (!node -> isKeyExist(node, s[j])) {
                cnt++;
                node -> insertKey(node, s[j]);
            }
            
            node = node -> getNextNode(node, s[j]);
        }
    }
    
    return cnt + 1;
}

// Brute Force TLE
class Trie {
public:
    Trie* children[26];
    bool isEnd;
    
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

bool isUniqueInsert(Trie *root, string &str) {
    Trie *curr = root;
    
    for (int i = 0; i < str.size(); i++) {
        if (curr -> children[str[i] - 'a'] == NULL)
            curr -> children[str[i] - 'a'] = new Trie();
            
        curr = curr -> children[str[i] - 'a'];
    }
    
    if (curr -> isEnd)
        return false;
        
    curr -> isEnd = true;
    return true;
}

int countDistinctSubstring(string s)
{
    Trie *root = new Trie();
    int cnt = 0;
    
    for (int i = 0; i < s.size(); i++) {
        string str = "";
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            if (isUniqueInsert(root, str))
                cnt++;
        }
    }
    
    return cnt + 1;
}


// Brute Force
// S.C. = O(n^3)
int countDistinctSubstrings(string &s)
{
    unordered_set<string> st;
    st.insert("");
    
    for (int i = 0; i < s.size(); i++) {
        string str = "";
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            st.insert(str);
        }
    }
    
    return st.size();
}