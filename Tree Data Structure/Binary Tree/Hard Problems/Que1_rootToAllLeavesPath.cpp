// GFG -> Root to Leaves Path
https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

// T.C. = O(N)
// S.C. = O(H)
void allLeavesPaths(Node* node, vector<vector<int>> &allPaths, vector<int> temp){
    if(node == NULL)
        return ;
    
    temp.push_back(node -> data) ;
    
    if(node -> left == NULL && node -> right == NULL){
        allPaths.push_back(temp) ;
        return ;
    }
    
    allLeavesPaths(node -> left, allPaths, temp) ;
    allLeavesPaths(node -> right, allPaths, temp) ;
    
} 

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> allPaths ;
    vector<int> temp ;
    allLeavesPaths(root, allPaths, temp) ;
    return allPaths ;
 }