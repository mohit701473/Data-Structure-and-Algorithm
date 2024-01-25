// LeetCode -. 222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/description/


// T.C. = O((logN)^2)
// S.C. = O(N)
class Solution {

    int solve(TreeNode* node){
        if(node == NULL)
            return 0 ;

        int lh = getLeftHeight(node) ;
        int rh = getRightHeight(node) ;

        if(lh == rh) return (1 << lh) - 1 ;

        return 1 + solve(node -> left) + solve(node -> right) ;
    }

    int getLeftHeight(TreeNode* node){
        int height = 0 ;

        while(node){
            height++ ;
            node = node -> left ;
        }

        return height ;
    }

    int getRightHeight(TreeNode* node){
        int height = 0 ;

        while(node){
            height++ ;
            node = node -> right ;
        }

        return height ;
    }

public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0 ;

        return solve(root) ;
    }
};