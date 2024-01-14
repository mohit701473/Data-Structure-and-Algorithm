// Approch 1 -> Recursive Inorder Traversal
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }

        solve(root -> left, ans) ;
        ans.push_back(root -> val) ;
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


// Approch 1 -> Itrative Inorder Traversal
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {} ;

        vector<int> inorder ;
        TreeNode* node = root ;
        stack<TreeNode*> st ;

        while(1){
            if(node != NULL){
                st.push(node) ;
                node = node -> left ;
            }
            else{
                if(st.empty()) break ;
                node = st.top() ;
                st.pop() ;
                inorder.push_back(node -> val) ;
                node = node -> right ;
            }
        }

        return inorder ;
    }
};