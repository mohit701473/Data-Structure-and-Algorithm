/*
Important: While we are solving problems using recusrion then our thinking is like that recursion always
            return the answre that we want but in actual it is not like that because their are some problems
            in which we have to find siomething else and we resturning something else from recursion.
*/
// Approch 1 -> Recursive
// T.C. = O(n)
// S.C. = O(n)
class Solution {
    
    int computeDiameterOfBT_returnHeightOfBT(TreeNode* node, int &maxDia){
        if(node == NULL)
            return 0 ;

        int l_height = computeDiameterOfBT_returnHeightOfBT(node -> left, maxDia) ;
        int r_height = computeDiameterOfBT_returnHeightOfBT(node -> right, maxDia) ;

        maxDia = max(maxDia, (l_height + r_height)) ;

        return max(l_height, r_height) + 1 ;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0 ;
        computeDiameterOfBT_returnHeightOfBT(root, maxDia) ;
        return maxDia ;
    }
};