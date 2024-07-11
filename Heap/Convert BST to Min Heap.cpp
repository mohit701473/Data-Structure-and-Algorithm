// GFG -> Convert BST to Min Heap
https://www.geeksforgeeks.org/convert-bst-min-heap/

/*
    // Conditoin for min heap
    // N < L and N < R 
    // N = node -> val, R = node -> right -> val, L = node -> left -> val
    // L < R in heap
    // So final inequality
    // N < R && N < L && L < R -> N < L < R => node left right = preorder

    // cond given:
    // BST is a CBT -> so structure of of heap and tree will be same only values are chahge
*/

void convertToMinHeap(TreeNode* node, int &i, vector<int>& in) {
    if(node == NULL)
        return;

    node -> val = in[i++];
    convertToMinHeap(node -> left, i, in);
    convertToMinHeap(node -> right, i, in);
}

void inorder(TreeNode* node, vector<int>& in) {
    if(node == NULL)
        return;
    
    inorder(node -> left, in);
    in.push_back(node -> val);
    inorder(node -> right, in);
}
void BSTToMinHeap(TreeNode* root) {
    vector<int> in;
    inorder(root, in);

    convertToMinHeap(root, 0, in);
}