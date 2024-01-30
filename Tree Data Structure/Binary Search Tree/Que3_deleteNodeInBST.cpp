// LeetCode -> 450. Delete Node in a BST
https://leetcode.com/problems/delete-node-in-a-bst/


// Approch 1:
// T.C. = O(log(N))
// S.C. = O(1)
class Solution {

    TreeNode* helper(TreeNode* node){
        if(node -> left == NULL) return node -> right ;
        if(node -> right == NULL) return node -> left ;

        TreeNode* curr = node -> left ;
        TreeNode* temp = node -> left ;
        TreeNode* node_right = node -> right ;
        while(curr -> right){
            curr = curr -> right ;
        }

        curr -> right = node_right ;
        return  temp ;

    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL ;

        if(root -> val == key) return helper(root) ;

        TreeNode* node = root ;
        while(node){
            if(node -> val > key){
                if(node -> left != NULL && node -> left -> val == key){
                    node -> left = helper(node -> left) ;
                    return root ;
                }
                else{
                    node = node -> left ;
                }
            }
            else{
                if(node -> right != NULL && node -> right -> val == key){
                    node -> right = helper(node -> right) ;
                    return root ;
                }
                else{
                    node = node -> right ;
                }
            }
        }

        return root ;
    }
};



// Approch 2:
// T.C. = O(log(N))
// S.C. = O(log(N))
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
            // your code goes here
    if(root == NULL) {
        return root ;
    }
    
    
    if(key == root -> val) {
        // 0 child 
        if(root -> left == NULL && root -> right == NULL) {
            delete root ;
            return NULL ;
        }
        
        //1 child 
        if(root -> left == NULL && root -> right != NULL) {
            TreeNode* temp = root -> right ;
            delete root ;
            return temp ;
        }
        
        if(root -> left != NULL && root -> right == NULL) {
            TreeNode* temp = root -> left ;
            delete root ;
            return temp ;
        }
        
        //2 child ;
        if(root -> left != NULL && root -> right != NULL) {
            TreeNode* temp = root -> right ;
            while(temp -> left != NULL) {
                temp = temp -> left ;
            }
            root -> val = temp -> val ;
            root -> right = deleteNode(root -> right , temp -> val) ;
            return root ;
        }
    }
    
    else if(key > root -> val){
        root -> right = deleteNode(root -> right , key) ;
        return root ;
    }
    else{
        root -> left = deleteNode(root -> left , key) ;
        return root ;
    }
    return root ;
    }
    
};