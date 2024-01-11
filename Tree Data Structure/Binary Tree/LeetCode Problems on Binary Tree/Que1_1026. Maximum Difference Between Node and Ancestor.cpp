// Approch 1 -> Brute Force
// T.C. = O(n^2)
// S.C. = O(h) ~~ O(n)  

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



// Approch 2 -> Optimal Solution
// T.C. = O(n)
// S.C. = O(h) ~~ O(n)  
class Solution {

    int findMaxDiff(TreeNode* node, pair<int, int> p){
        if(node == NULL){
            return abs(p.first - p.second) ;
        }

        p.first = max(p.first, node -> val) ;
        p.second = min(p.second, node -> val) ;

        int leftSubTree_max = findMaxDiff(node -> left, p) ;
        int rightSubTree_max = findMaxDiff(node -> right, p) ;

        return max(leftSubTree_max, rightSubTree_max) ;
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        pair<int, int> p = make_pair(INT_MIN, INT_MAX) ; // this pair will store the (max, min) between root to leaf path
        return findMaxDiff(root, p) ;
    }
};