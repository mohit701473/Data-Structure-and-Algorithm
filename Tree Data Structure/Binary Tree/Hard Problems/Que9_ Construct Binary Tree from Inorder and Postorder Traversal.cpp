// LeetCode -> 106. Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/


class Solution {

    TreeNode* generateBT(vector<int> &postorder, int post_st, int post_end, vector<int> &inorder, int in_st, int in_end, unordered_map<int, int> &inMap){

        if(post_st > post_end || in_st > in_end)
            return NULL ;

        TreeNode* root = new TreeNode(postorder[post_end]) ;

        int rootIdx = inMap[root -> val] ;
        int left_eles = rootIdx - in_st ;

        root -> left = generateBT(postorder, post_st, post_st+left_eles+-1, inorder, in_st, rootIdx-1, inMap) ;

        root -> right = generateBT(postorder, post_st+left_eles, post_end-1, inorder, rootIdx+1, in_end, inMap) ;

        return root ;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap ;

        for(int i=0 ; i<inorder.size() ; i++)
            inMap[inorder[i]] = i ;

        return generateBT(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap) ;
    }
};