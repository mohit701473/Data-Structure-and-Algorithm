// LeetCode -> 653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/


// T.C. = O(N)
// S.C. = O(H) + O(H)
class BSTIterator {

    stack<TreeNode*> st_next ;
    stack<TreeNode*> st_before ;

public:
    BSTIterator(TreeNode* root) {
        st_next = stack<TreeNode*> () ;
        st_before = stack<TreeNode*> () ;

        TreeNode* curr = root ;
        while(curr){
            st_next.push(curr) ;
            curr = curr -> left ;
        }

        curr = root ;
        while(curr){
            st_before.push(curr) ;
            curr = curr -> right ;
        }
    }
    
    int next() {
        TreeNode* node = st_next.top() ;
        st_next.pop() ;
        int ele = node -> val ;
        node = node -> right ;
        while(node){
            st_next.push(node) ;
            node = node -> left ;
        }

        return ele ;
    }
    
    bool hasNext() {
        return !st_next.empty() ;
    }

    int before(){
        TreeNode* node = st_before.top() ;
        st_before.pop() ;

        int ele = node -> val ;
        node = node -> left ;
        while(node){
            st_before.push(node) ;
            node = node -> right ;
        }

        return ele ;
    }

    bool hasBeofre(){
        return !st_before.empty() ;
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false ;

        BSTIterator it(root) ;
        int i = it.next() ;
        int j = it.before() ;

        while(i < j){
            if(i + j == k) return true ;
            if(i + j < k){
                i = it.next() ;
            }else{
                j = it.before() ;
            }
        }

        return false ;
    }
};