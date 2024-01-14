// LeetCode -> 
https://leetcode.com/problems/binary-tree-right-side-view/description/

// Approch -> first node of every level in recursive preorder
// T.C. = O(N)
// S.C. = O(H)
class Solution {

    void reverse_preorder(TreeNode* node, int level, vector<int> &ans){
        if(node == NULL)
            return ;

        if(level == ans.size()){
            ans.push_back(node -> val) ;
        }

        reverse_preorder(node -> right, level+1, ans) ;
        reverse_preorder(node -> left, level+1, ans) ;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {} ;

        vector<int> ans ;
        reverse_preorder(root, 0, ans) ;
        return ans ;
    }
};



// Approch -> last node of every level
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {} ;

        vector<int> ans ;
        queue<TreeNode*> q ;
        q.push(root) ;
        q.push(NULL) ;

        while(!q.empty()){
            TreeNode* node = q.front() ;
            q.pop() ;

            if(node == NULL){
                if(!q.empty()){
                    q.push(NULL) ;
                }
            }
            else{
                if(q.front() == NULL){
                    ans.push_back(node -> val) ;
                }

                if(node -> left) q.push(node -> left) ;
                if(node -> right) q.push(node -> right) ;
            }
        }

        return ans ;
    }
};