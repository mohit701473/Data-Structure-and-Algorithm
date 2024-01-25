// LeetCode -> 863. All Nodes Distance K in Binary Tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/


// T.C. = O(N)
// S.C. = O(N)
class Solution {

    unordered_map<TreeNode*, TreeNode*> parent ;

    void parentMapping(TreeNode* root){
        queue<TreeNode*> q ;
        q.push(root) ;

        while(!q.empty()){
            int size = q.size() ;

            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front() ;
                q.pop() ;

                if(node -> left){
                    parent[node -> left] = node ;
                    q.push(node -> left) ;
                }

                if(node -> right){
                    parent[node -> right] = node ;
                    q.push(node -> right) ;
                }
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int dis = 0 ;
        parentMapping(root) ;
        unordered_map<TreeNode*, bool> visited ;
        queue<TreeNode*> q ;
        q.push(target) ;
        visited[target] = true ;

        while(!q.empty() && dis < k){
            int size = q.size() ;

            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front() ;
                q.pop() ;

                if(node -> left != NULL && visited[node -> left] == false){
                    q.push(node -> left) ;
                    visited[node -> left] = true ;
                }

                if(node -> right != NULL && visited[node -> right] == false){
                    q.push(node -> right) ;
                    visited[node -> right] = true ;
                }

                if(parent.find(node) != parent.end() && visited[parent[node]] == false){
                    q.push(parent[node]) ;
                    visited[parent[node]] = true ;
                }
            }

            dis++ ;
        }

        vector<int> ans ;

        while(!q.empty()){
            TreeNode* node = q.front() ;
            q.pop() ;
            ans.push_back(node -> val) ;
        }

        return ans ;

    }
};