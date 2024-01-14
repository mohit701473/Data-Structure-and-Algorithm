// GFG -> Top View of Binary Tree 
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Approch -> Same as vertical order traversal
// T.C. = O(Nlog(N))
// S.C. = O(N)
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp ;
        queue<pair<Node*, int>> q ;
        q.push({root, 0}) ;
        
        while(!q.empty()){
            pair<Node*, int> p = q.front() ;
            q.pop() ;
            
            Node* node = p.first ;
            int line = p.second ;
            
            if(mp.find(line) == mp.end()){
                mp[line] = node -> data ;
            }
            
            if(node -> left != NULL){
                q.push({node -> left, line-1}) ;
            }
            if(node -> right != NULL){
                q.push({node -> right, line+1}) ;
            }
        }
        
        vector<int> ans ;
        for(auto it: mp){
            ans.push_back(it.second) ;
        }
        
        return ans ;
    }

};