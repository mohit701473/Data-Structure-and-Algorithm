// LeetCode -> 173. Binary Search Tree Iterator
https://leetcode.com/problems/binary-search-tree-iterator/

// Approch -> Inorder
// T.C. = O(1)
// S.C. = O(H) worst case O(N) skewed BST
class BSTIterator {

    stack<TreeNode*> st ;

public:
    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*> () ;
        while(root){
            st.push(root) ;
            root = root -> left ;
        }
    }
    
    int next() {
        TreeNode* node = st.top() ;
        st.pop() ;
        int ele = node -> val ;
        node = node -> right ;
        while(node){
            st.push(node) ;
            node = node -> left ;
        }

        return ele ;
    }
    
    bool hasNext() {
        return !st.empty() ;
    }
};