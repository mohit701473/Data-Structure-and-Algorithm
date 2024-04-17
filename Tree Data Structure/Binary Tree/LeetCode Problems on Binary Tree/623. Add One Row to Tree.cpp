// LeetCode -> 623. Add One Row to Tree
https://leetcode.com/problems/add-one-row-to-tree/description/


class Solution {
public:
    void solve(TreeNode* node, int val, int depth){
        if(node == NULL)
            return ;

        if(depth == 1){
            TreeNode* temp_l = new TreeNode(val) ;
            TreeNode* temp_r = new TreeNode(val) ;

            temp_l -> left = node -> left ;
            temp_r -> right = node -> right ;

            node -> left = temp_l ;
            node -> right = temp_r ;

            return ;
        }

        solve(node -> left, val,  depth-1) ;
        solve(node -> right, val, depth-1) ;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val) ;
            temp -> left = root ;
            return temp ;
        }

        solve(root, val, depth-1) ;
        return root ;
    }
};