// LeetCode -> 
https://leetcode.com/problems/symmetric-tree/

// Approch -> first node of every level in recursive preorder
// T.C. = O(N)
// S.C. = O(H)
class Solution {

    bool solve(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL) return true ;
        if((node1 == NULL && node2 != NULL) || (node1 != NULL && node2 == NULL)) return false ;

        if(node1 -> val != node2 -> val)
            return false ;

        int subtree1 = solve(node1 -> left, node2 -> right) ;
        int subtree2 = solve(node1 -> right, node2 -> left) ;

        return (subtree1 & subtree2) ;
    }

public:
    bool isSymmetric(TreeNode* root) {
        return solve(root -> left, root -> right) ;
    }
};