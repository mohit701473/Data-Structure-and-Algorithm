// LeetCode -> 1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


// Approch -> 1: Brute Force Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL ;

        for(int i=0 ; i<preorder.size() ; i++){
            TreeNode* node = new TreeNode(preorder[i]) ;
            if(root == NULL){
                root = node ;
                continue;
            }
            else{
                TreeNode* curr = root ;
                TreeNode* prev = NULL ;

                while(curr){
                    prev = curr ;
                    if(node -> val < curr -> val){
                        curr = curr -> left ;
                    }else{
                        curr = curr -> right ;
                    }
                }

                if(node -> val < prev -> val){
                    prev -> left = node ;
                }
                else{
                    prev -> right = node ;
                }
            }
        }

        return root ;
    }
};


// Approch -> 2: Optimal Approch
// T.C. = O(N)
// S.C. = O(N)
class Solution {

    TreeNode* bst(vector<int> &A, int &i, int ub){
        if(i >= A.size() || A[i] > ub)
            return NULL ;

        TreeNode* node = new TreeNode(A[i++]) ;
        node -> left = bst(A, i, node -> val) ;
        node -> right = bst(A, i, ub) ;
        return node ;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;
        return bst(preorder, i, INT_MAX) ;
    }
};