#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int cnt, num;
    TrieNode *left;
    TrieNode *right;

    TrieNode() {
        cnt = 0;
        num = 0;
        left = right = NULL;
    }
};

TrieNode* getTrieNode() {
    return new TrieNode();
}

void insert(TrieNode *root, int x) {
    TrieNode* curr = root;

    for (int i = 31; i >=0; i--) {
        int bit = x & (1 << i);
        if (bit) { // bit = 1
            if (curr -> right == NULL)
                curr -> right = getTrieNode();
            curr = curr -> right;
            curr -> cnt++;
        } else { // bit = 0
            if (curr -> left == NULL)
                curr -> left = getTrieNode();
            curr = curr -> left;
            curr -> cnt++;
        }
    }

    curr -> num = x;
}

void remove(TrieNode *root, int x) {
    TrieNode* curr = root;
    bitset<32> b(x);

    for (int i = 31; i >=0; i--) {
        int bit = b[i];
        if (bit) { // bit = 1
            curr = curr -> right;
            curr -> cnt--;
        } else { // bit = 0
            curr = curr -> left;
            curr -> cnt--;
        }
    }
}

int findMaximumXOR(TrieNode *root, int x) {
    TrieNode* curr = root;
    
    for (int i = 31; i >= 0 && curr != NULL; i--) {
        int bit = x & (1 << i);
        if (bit) {
            if (curr -> left != NULL && curr -> left -> cnt > 0)
                curr = curr -> left;
            else curr = curr -> right;
        } else {
            if (curr -> right != NULL && curr -> right -> cnt > 0)
                curr = curr -> right;
            else curr = curr -> left;
        }
    }

    if (curr == NULL)
        return x;

    return max (x, x ^ curr -> num); 
    // bcz multiset always contain 0 it is given
    // why are are return max(x, x ^ curr -> num)
    // input
    // 4
    // ? 1
    // + 1
    // + 4
    // ? 5
    // output
    // 1
    // 5

}

int main()
{
    // int t;
    // cout << "Enter t: ";
    // cin >> t;
    // while (t--) {
        int q;
        cin >> q;
        TrieNode *root = getTrieNode();
        while (q--) {
            char ch;
            cin >> ch;
            int x;
            cin >> x;
            if (ch == '+')
                insert(root, x);
            else if (ch == '-')
                remove(root, x);
            else cout << findMaximumXOR(root, x) << endl;
            // cout << "q: " << q << endl;
        }
    // }
}