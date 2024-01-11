// Approch 1 -> Brute Force
// T.C. = O(n^2)
// S.C. = O()

class Solution {

    void getMaxDiffenernce(TreeNode* node, int ancestor, int &maxi){
        if(node == NULL) return ;

        getMaxDiffenernce(node -> left, ancestor, maxi) ;
        getMaxDiffenernce(node -> right, ancestor, maxi) ;

        maxi = max(maxi, abs(ancestor - node -> val)) ;
    }

    void preorderTraversal(TreeNode* node, int &maxi){
        if(node == NULL)
            return ;

        getMaxDiffenernce(node, node -> val, maxi) ;
        preorderTraversal(node -> left, maxi) ;
        preorderTraversal(node -> right, maxi) ;

    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxi = INT_MIN ;
        preorderTraversal(root, maxi) ;
        return maxi ;
    }
};