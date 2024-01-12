// Approch -> Similar as diameter of BT
// T.C. = O(H) ~~ O(N)
// S.C. = O(H) ~~ O(N)
class Solution {

    int computeMaxPathSum_returnNodeSumWith_maxOf_LSum_Or_RSUM(TreeNode* node, int &max_pathSum){
        if(node == NULL)
            return 0 ;

        int left_sum = max(0, computeMaxPathSum_returnNodeSumWith_maxOf_LSum_Or_RSUM(node -> left, max_pathSum)) ;
        int right_sum = max(0, computeMaxPathSum_returnNodeSumWith_maxOf_LSum_Or_RSUM(node -> right, max_pathSum)) ;

        max_pathSum = max(max_pathSum, (node -> val + left_sum + right_sum)) ;

        return node -> val + max(left_sum , right_sum) ;
    }

public:
    int maxPathSum(TreeNode* root) {
        int max_pathSum = INT_MIN ;
        computeMaxPathSum_returnNodeSumWith_maxOf_LSum_Or_RSUM(root, max_pathSum) ;
        return max_pathSum ;
    }
};