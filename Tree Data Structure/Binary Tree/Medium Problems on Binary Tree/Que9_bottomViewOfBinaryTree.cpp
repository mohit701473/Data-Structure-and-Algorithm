// GFG -> Bottom view of Binary Tree 
https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Approch -> Same as vertical order traversal
// T.C. = O(Nlog(N))
// S.C. = O(N)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int> mp ;
        queue<pair<Node*, int>> q ;
        q.push({root, 0}) ;
        
        while(!q.empty()){
            pair<Node*, int> p = q.front() ;
            q.pop() ;
            
            Node* node = p.first ;
            int vertical = p.second ;
            
            mp[vertical] = node -> data ;
            
            if(node -> left) q.push({node -> left, vertical-1}) ;
            if(node -> right) q.push({node -> right, vertical+1}) ;
        }
        
        vector<int> ans ;
        for(auto it: mp){
            ans.push_back(it.second) ;
        }
        
        return ans ;
    }
};




// Approch -> 
// T.C. = O(Nlog(N))
// S.C. = O(N)
class Solution {

    void reverse_preorder(TreeNode* node, int level, vector<int> &ans){
        if(node == NULL)
            return ;

        if(level == ans.size()){
            ans.push_back(node -> val) ;
        }

        reverse_preorder(node -> right, level+1, ans) ;
        reverse_preorder(node -> left, level+1, ans) ;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {} ;

        vector<int> ans ;
        reverse_preorder(root, 0, ans) ;
        return ans ;
    }
};