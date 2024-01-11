// Approch 1 -> Recursive Preorder Traversal
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }

        ans.push_back(root -> val) ;
        solve(root -> left, ans) ;
        solve(root -> right, ans) ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        if(root == NULL)
            return ans ;

        solve(root, ans) ;
        return  ans ;
    }
};


// Approch 1 -> Itrative Preorder Traversal
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {} ;

        vector<int> preorder ;
        stack<TreeNode*> st ;
        st.push(root) ;

        while(!st.empty()){
            TreeNode* node = st.top() ;
            st.pop() ;

            preorder.push_back(node -> val) ;

            if(node != NULL && node -> right != NULL) st.push(node -> right) ;
            if(node != NULL && node -> left != NULL) st.push(node -> left) ;
        }

        return preorder ;
    }
};