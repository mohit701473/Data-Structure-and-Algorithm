// LetCode -> 129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

class Solution {
public:

    int solve(TreeNode* node, int sum){
        if(node == NULL)
            return 0 ;

        sum *= 10 ;
        sum += node -> val ;

        if(node -> left == NULL && node -> right == NULL){
            return sum;
        }

        int l = solve(node -> left, sum) ;
        int r = solve(node -> right, sum) ;

        return l+r ;
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0) ;
    }
};