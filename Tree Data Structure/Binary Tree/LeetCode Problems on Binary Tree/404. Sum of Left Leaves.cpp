// LeetCode -> 404. Sum of Left Leaves
https://leetcode.com/problems/sum-of-left-leaves/description/


class Solution {
public:

    int solve(TreeNode* node, bool isLeft){
        if(node == NULL)    
            return 0 ;
        
        if(node -> left == NULL && node -> right == NULL && isLeft){
            return node -> val ;
        }

        int lSum = solve(node -> left, true) ;
        int rSum = solve(node -> right, false) ;

        return lSum + rSum ;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false) ;
    }
};