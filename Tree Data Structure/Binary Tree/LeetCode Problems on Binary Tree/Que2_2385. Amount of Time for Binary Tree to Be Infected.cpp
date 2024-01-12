// Approch -> Same as Time to burn a Binary Tree
// T.C. = O(N + N)
// S.C. = O()
class Solution {
    unordered_map<int, TreeNode*> child_to_parent ; // child to parent mapping

    int timeRequiredToBinaryTreeInfected(TreeNode* node){
        int time = 0 ;
        unordered_map<int, bool> visited ;
        queue<TreeNode*> q ;
        q.push(node) ;
        visited[node -> val] = true ;
        

        while(!q.empty()){
            bool flag = false ;
            int size = q.size() ;

            for(int i=0 ; i<size ; i++){
                TreeNode* temp = q.front() ;
                q.pop() ;

                if(child_to_parent.find(temp -> val) != child_to_parent.end() && !visited[child_to_parent[temp -> val] -> val]){
                    q.push(child_to_parent[temp -> val]) ;
                    visited[child_to_parent[temp -> val] -> val] = true ;
                    flag = true ;
                }

                if(temp != NULL && temp -> left != NULL && !visited[temp -> left -> val]){
                    q.push(temp -> left) ;
                    visited[temp -> left -> val] = true ;
                    flag = true ;
                }

                if(temp != NULL && temp -> right != NULL && !visited[temp -> right -> val]){
                    q.push(temp -> right) ;
                    visited[temp -> right -> val] = true ;
                    flag = true ;
                }
            }

            if(flag){
                time++ ;
            }
        }

        return time ; 
    }

    TreeNode* child_to_parent_mapping(TreeNode* root, int start){

        TreeNode* node = NULL ;

        queue<TreeNode*> q ;
        q.push(root) ;

        while(!q.empty()){
            TreeNode* temp = q.front() ; 
            q.pop() ;

            if(temp -> val == start){
                node = temp ;
            }

            if(temp != NULL && temp -> left != NULL){
                int child = temp -> left -> val ;
                child_to_parent[child] = temp ;
                q.push(temp -> left) ;
            }

            if(temp != NULL && temp -> right != NULL){
                int child = temp -> right -> val ;
                child_to_parent[child] = temp ;
                q.push(temp -> right) ;
            }
        }

        return node ;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        
        TreeNode* starting_node = child_to_parent_mapping(root, start) ;

        return timeRequiredToBinaryTreeInfected(starting_node) ;
        
    }
};