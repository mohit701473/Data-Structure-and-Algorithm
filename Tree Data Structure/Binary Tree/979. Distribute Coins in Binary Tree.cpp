// LeetCode -> 979. Distribute Coins in Binary Tree
https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

class Solution {
public:

    int solve(TreeNode* node, int& steps){
        if(node ==  NULL)
            return 0;

        int l = solve(node -> left, steps);
        int r = solve(node -> right, steps);

        steps += abs(l) + abs(r);

        return node -> val + l + r - 1;
    }

    int distributeCoins(TreeNode* root) {
        int steps = 0;
        solve(root, steps);
        return steps;
    }
};