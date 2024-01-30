// LeetCode -> 235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


// T.C. = O(log(N))
// S.C. = O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root ;

        while(curr){
            if((curr -> val > p -> val && curr -> val < q -> val) || (curr -> val < p -> val && curr -> val > q -> val) || (curr == p ) || (curr == q)){
                return curr ;
            }

            if(curr -> val < p -> val && curr -> val < q -> val)
                curr = curr -> right ;
            else
                curr = curr -> left ;
        }

        return curr ;
    }
};