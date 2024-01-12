// Approch -> Same as level order traversal
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {} ;

        vector<vector<int>> result ;
        bool rightToLeft = true ;
        queue<TreeNode*> q ;
        q.push(root) ;

        while(!q.empty()){

            int size = q.size() ;
            vector<int> temp(size) ;

            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front() ;
                q.pop() ;

                if(node != NULL && node -> left != NULL){
                    q.push(node -> left) ;
                }
                if(node != NULL && node -> right != NULL){
                    q.push(node -> right) ;
                }

                int idx = rightToLeft ? i : size - i - 1 ;

                temp[idx] = node -> val ;
            }

            rightToLeft = !rightToLeft ;
            result.push_back(temp) ;
        }

        return result ;
    }
};