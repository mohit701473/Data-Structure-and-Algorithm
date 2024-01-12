// Approch 1 -> Recursive
// T.C. = O(n)
// S.C. = O(n)
class Solution {

    int heightOfBinaryTree(TreeNode* node){
        if(node == NULL)
            return 0 ;

        int h_left = heightOfBinaryTree(node -> left) ;
        int h_right = heightOfBinaryTree(node -> right) ;

        int height = max(h_left, h_right) + 1 ;

        return height ;
    }

public:
    int maxDepth(TreeNode* root) {
        
        return heightOfBinaryTree(root) ;
    }
};



// Approch 1 -> Recursive
// T.C. = O(n)
// S.C. = O(n)
class Solution {

    int depthOfBinaryTree(TreeNode* node){
        if(node == NULL || (node -> left == NULL && node -> right ==  NULL))
            return 0 ;

        int left_depth = depthOfBinaryTree(node -> left) ;
        int right_depth = depthOfBinaryTree(node -> right) ;

        int depth = max(left_depth, right_depth) + 1 ;

        return depth ;
    }

public:
    int maxDepth(TreeNode* root) {

        if(root == NULL) return 0 ;
        
        return depthOfBinaryTree(root) ;
    }
};