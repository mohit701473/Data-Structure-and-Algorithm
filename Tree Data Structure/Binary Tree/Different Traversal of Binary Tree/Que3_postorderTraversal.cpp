// Approch 1 -> Recursive Postorder Traversal
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:

    void solve(TreeNode* root, vector<int> &ans){
        if(root == NULL)
            return ;

        solve(root -> left, ans) ;
        solve(root -> right, ans) ;
        ans.push_back(root -> val) ;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;
        if(root == NULL)
            return ans ;

        solve(root, ans) ;
        return ans ;
    }
};


// Approch 2 -> Itrative Postorder Traversal using 2 stack
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) 
            return {} ;

        stack<TreeNode*> st1 ;
        vector<int> st2 ;

        st1.push(root) ;

        while(!st1.empty()){
            // step -> 1:
            TreeNode* node = st1.top() ;
            st1.pop() ;
            st2.push_back(node -> val) ;

            // step -> 2:
            if(node != NULL && node -> left != NULL)
                st1.push(node -> left) ;

            // step -> 3:
            if(node != NULL && node -> right != NULL)
                st1.push(node -> right) ;
        }

        reverse(st2.begin(), st2.end()) ;
        
        return st2 ;
    }
};