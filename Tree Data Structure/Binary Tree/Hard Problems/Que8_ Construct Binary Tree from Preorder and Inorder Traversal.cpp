// LeetCode -> 105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/



class Solution {

    TreeNode* generateBT(vector<int> &preorder, int preSt, int preEnd, vector<int> &inorder, int inSt, int inEnd, unordered_map<int, int> &inMap){

        if(preSt > preEnd || inSt > inEnd)
            return NULL ;

        TreeNode* root = new TreeNode(preorder[preSt]) ;

        int rootIdx = inMap[root -> val] ;
        int left_eles = rootIdx - inSt ;

        root -> left = generateBT(preorder, preSt+1, preSt + left_eles, inorder, inSt, rootIdx-1, inMap) ;

        root -> right = generateBT(preorder, preSt + left_eles + 1, preEnd, inorder, rootIdx+1, inEnd, inMap) ;

        return root ;
    }
    

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap ;

        for(int i=0 ; i<inorder.size() ; i++)
            inMap[inorder[i]] = i ;

        return generateBT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap) ;
    }
};