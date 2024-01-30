// LeetCode -> 98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/


// T.C. = O(N) + O(N)
// S.C. = O(N) + O(N)
class Solution {

    void inorder(TreeNode* node, vector<int> &in){
        if(node == NULL)
            return ;

        inorder(node -> left, in) ;
        in.push_back(node -> val) ;
        inorder(node -> right, in) ;   
    }

public:
    bool isValidBST(TreeNode* root) {
        vector<int> in ;
        inorder(root, in) ;

        for(int i=1 ; i<in.size() ; i++){
            if(in[i] <= in[i-1]) 
                return false ;
        }

        return true ;
    }
};



// T.C. = O(N)
// S.C. = O(N)
class Solution {

    bool inorder(TreeNode* node, double mini, double maxi){
        if(node == NULL)
            return true ;

        if(mini >= node -> val || node -> val >= maxi)
            return false ;

        bool l = inorder(node -> left, mini, node -> val) ;
        bool r = inorder(node -> right, node -> val, maxi) ;

        return l & r ;
    }

public:
    bool isValidBST(TreeNode* root) {
        double mini = double(INT_MIN) - 1 ;
        double maxi = double(INT_MAX) + 1 ;
        return inorder(root, mini, maxi) ;
    }
};