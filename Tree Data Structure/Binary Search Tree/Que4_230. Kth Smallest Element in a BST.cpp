// LeetCode -> 230. Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/


// Approch -> 1: store the inoredr
// T.C. = O(N)
// S.C. = O(N) + O(N)
class Solution {

    void inoredrTraversal(TreeNode* node, vector<int> &inorder){
        if(node == NULL)
            return ;

        inoredrTraversal(node -> left, inorder) ;
        inorder.push_back(node -> val) ;
        inoredrTraversal(node -> right, inorder) ;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder ;
        inoredrTraversal(root, inorder) ;
        return inorder[k-1] ;
    }
};



// Approch -> 2:
// T.C. = O(N)
// S.C. = O(N)
class Solution {

    void inoredrTraversal(TreeNode* node, int &k, int &ans){
        if(node == NULL)
            return ;

        inoredrTraversal(node -> left, k, ans) ;
        k-- ;
        if(k == 0) ans = node -> val ;
        inoredrTraversal(node -> right, k, ans) ;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans ;
        inoredrTraversal(root, k, ans) ;
        return ans ;
    }
};



// Approch -> 3: Morris Traversal
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> inorder ;
        int ans = -1 ;
        TreeNode* curr = root ;

        while(curr != NULL){
            if(curr -> left == NULL){
                // inorder.push_back(curr -> val) ;
                k-- ;
                if(k==0){// return curr -> val => error
                    ans =  curr -> val ;
                    // break => error
                }
                curr = curr -> right ;
            }
            else{
                TreeNode* prev = curr -> left ;
                while(prev -> right && prev -> right != curr)
                    prev = prev -> right ;

                if(prev -> right == NULL){
                    prev -> right = curr ;
                    curr = curr -> left ;
                }
                else{
                    prev -> right = NULL ;
                    // inorder.push_back(curr -> val) ;
                    k-- ;
                    if(k==0){ // return curr -> val => error
                        ans =  curr -> val ;
                        // break => error
                    }
                    curr = curr -> right ;
                }
            }
        }

        return ans ;
    }
};