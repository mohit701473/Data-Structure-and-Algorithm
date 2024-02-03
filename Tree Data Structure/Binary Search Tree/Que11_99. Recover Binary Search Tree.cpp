// LeetCode -> 99. Recover Binary Search Tree
https://leetcode.com/problems/recover-binary-search-tree/


// T.C. = O(N)
// S.C. = O(1)
class Solution {

    TreeNode* first = NULL ;
    TreeNode* middle = NULL ;
    TreeNode* last = NULL ;
    TreeNode* prev = NULL ;

    void inorder(TreeNode* node){
        if(node == NULL)
            return ;

        inorder(node -> left) ;
        if(prev && node -> val < prev -> val){
            if(!first){
                first = prev ;
                middle = node ;
            }
            else{
                last = node ;
            }
        }
        prev = node ;
        inorder(node -> right) ;
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root) ;

        if(last){
            swap(first -> val, last -> val) ;
            return ;
        }

        swap(first -> val, middle -> val) ;
    }
};