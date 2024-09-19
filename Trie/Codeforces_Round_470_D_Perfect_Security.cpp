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
    bitset<32> b(x);

    for (int i = 31; i >=0; i--) {
        int bit = b[i];
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

int findMinimumXOR(TrieNode *root, int x) {
    TrieNode* curr = root;
    bitset<32> b(x);

    for (int i = 31; i >= 0; i--) {
        int bit = b[i];
        if (bit == 0) {
            if (curr -> left != NULL && curr -> left -> cnt > 0)
                curr = curr -> left;
            else curr = curr -> right;
        } else {
            if (curr -> right != NULL && curr -> right -> cnt > 0)
                curr = curr -> right;
            else curr = curr -> left;
        }
    }

    // if (curr == NULL)
    //     return x;
    int num = curr -> num;
    // cout << "num: " << num << endl;
    remove(root, num);
    return (x ^ num); 
}

int main()
{
    // int t;
    // cout << "Enter t: ";
    // cin >> t;
    // while (t--) {
        int N;
        cin >> N;
        TrieNode *root = getTrieNode();
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            insert(root, x);
        }

        for (int i = 0; i < N; i++)
            cout << findMinimumXOR(root, arr[i]) << " ";

    //     cout << endl << endl;
    // }
}