// LeetCode -> 701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/description/


// T.C. = O(log(N))
// S.C. = O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val) ;

        if(root == NULL)
            return node ;

        TreeNode* curr = root ;
        TreeNode* prev = NULL ;

        while(curr){
            prev = curr ;
            if(curr -> val < val)
                curr = curr -> right ;
            else curr = curr -> left ;
        }

        if(prev -> val < val)
            prev -> right = node ;
        else prev ->  left = node ;

        return root ;
    }
};