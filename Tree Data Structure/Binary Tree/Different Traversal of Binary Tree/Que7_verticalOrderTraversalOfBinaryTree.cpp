class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>> mp ;
        queue<pair<TreeNode*, pair<int, int>>> q ;
        q.push({root, {0,0}}) ;

        while(!q.empty()){
            // step -> 1: pop out from q
            pair<TreeNode*, pair<int, int>> node = q.front() ;
            q.pop() ;

            TreeNode* temp = node.first ;
            int vertical = node.second.first ;
            int level = node.second.second ;

            // step -> 2: if left and right are not NULL of the node then insert them into q 
            if(temp != NULL && temp -> left != NULL){
                pair<TreeNode*, pair<int, int>> node_left = {temp -> left, {vertical-1, level+1}} ;
                q.push(node_left) ;
            }
            if(temp != NULL && temp -> right != NULL){
                pair<TreeNode*, pair<int, int>> node_right = {temp -> right, {vertical+1, level+1}} ;
                q.push(node_right) ;
            }

            // step -> 3: now insert into mp DS 
            mp[vertical][level].insert(temp -> val) ;
        }


        vector<vector<int>> ans ;
        for(auto p: mp){
            vector<int> col ;
            for(auto k: p.second){
                col.insert(col.end(), k.second.begin(), k.second.end()) ;
            }
            
            ans.push_back(col) ;
        }

        return ans ;
    }
};