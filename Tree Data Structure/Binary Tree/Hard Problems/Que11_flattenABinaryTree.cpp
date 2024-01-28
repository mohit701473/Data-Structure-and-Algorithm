// LeetCode -> 114. Flatten Binary Tree to Linked List
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    TreeNode* prev = NULL ;

    void solve(TreeNode* node){
        if(node == NULL)
            return ;

        solve(node -> right) ;
        solve(node -> left) ;

        node -> right = prev ;
        node -> left = NULL ;
        prev = node ;
    }

    void flatten(TreeNode* root) {
        solve(root) ;
        root = prev ;
    }
};



// Approch -2: Morris traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root ;
        while(curr){
            if(curr -> left){
                TreeNode* prev = curr -> left ;
                while(prev -> right) prev = prev -> right ;
                prev -> right = curr -> right ;
                curr -> right = curr -> left ;
                curr -> left = NULL ;
            }
            curr = curr -> right ;
        }
    }
};