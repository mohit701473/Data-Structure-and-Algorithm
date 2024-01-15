// LeetCode -> 662. Maximum Width of Binary Tree
https://leetcode.com/problems/maximum-width-of-binary-tree/description/


// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        double maxWidth = 0 ;
        queue<pair<TreeNode*, double>> q ;
        q.push({root, 0}) ;

        while(!q.empty()){
            int size = q.size() ;
            double level_min_idx = q.front().second, level_first_idx = -1, level_last_idx = -1 ;
            
            for(int i=0 ; i<size ; i++){
                pair<TreeNode*, double> p = q.front() ;
                q.pop() ;

                TreeNode* node = p.first ;
                double idx = p.second - level_min_idx ;

                if(i==0){
                    level_first_idx = idx ;
                }
                if(i==size-1){
                    level_last_idx = idx ;
                }

                if(node -> left){
                    pair<TreeNode*, double> p_left = {node -> left, (2*(idx)+1)} ;
                    q.push(p_left) ;
                }
                if(node -> right){
                    pair<TreeNode*, double> p_right = {node -> right, (2*(idx)+2)} ;
                    q.push(p_right) ;
                }
            }

            maxWidth = max(maxWidth, (level_last_idx - level_first_idx)+1) ;
        }

        return maxWidth;
    }
};