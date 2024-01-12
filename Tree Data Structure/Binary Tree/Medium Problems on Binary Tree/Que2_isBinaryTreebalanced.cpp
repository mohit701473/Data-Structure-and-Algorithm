// Approch 1 -> 
// T.C. = O(N)
// S.C. = O(N)
class Solution {

    int computeIsBalanced_returnHeight(TreeNode* node, bool &h_balanced){
        if(node == NULL)
            return 0 ;

        if(!h_balanced){
            return 0 ;
        }

        int h_left = computeIsBalanced_returnHeight(node -> left, h_balanced) ;
        int h_right = computeIsBalanced_returnHeight(node -> right, h_balanced) ;

        if(abs(h_left - h_right) > 1){
            h_balanced = false ;
        } 

        int height = max(h_left, h_right) + 1 ;
        return height ;
    }

public:
    bool isBalanced(TreeNode* root) {
        bool h_balanced = true ;
        computeIsBalanced_returnHeight(root, h_balanced) ;
        return h_balanced;
    }
};