// Code Studio -  Time To Burn Tree
https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM


BinaryTreeNode<int>* childToParentMapping(BinaryTreeNode<int>* root, int start, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent)
{
    BinaryTreeNode<int>* temp = NULL ;
    queue<BinaryTreeNode<int>*> q ;
    q.push(root) ;


    while(!q.empty()){
        int size = q.size() ;

        for(int i=0 ; i<size ; i++){
            BinaryTreeNode<int>* node = q.front() ;
            q.pop() ;

            if(node -> data == start){
                temp = node ;
            }

            if(node -> left){
                q.push(node -> left) ;
                parent[node -> left] = node ;
            }

            if(node -> right){
                q.push(node -> right) ;
                parent[node -> right] = node ;
            }
        }
    }

    return temp ;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent ;
    BinaryTreeNode<int>* node = childToParentMapping(root, start, parent) ; 

    int time = -1 ;
    unordered_map<BinaryTreeNode<int>*, bool> mp ;
    queue<BinaryTreeNode<int>*> q ;
    q.push(node) ;
    mp[node] = true ;

    while(!q.empty()){
        int size = q.size() ;
        time++ ;
        for(int i=0 ; i<size ; i++){
            BinaryTreeNode<int>* temp = q.front() ;
            q.pop() ;

            if(temp -> left != NULL && !mp[temp -> left]){
                q.push(temp -> left) ;
                mp[temp -> left] = true ;
            }

            if(temp -> right != NULL && !mp[temp -> right]){
                q.push(temp -> right) ;
                mp[temp -> right] = true ;
            }

            if(parent.find(temp) != parent.end() && !mp[parent[temp]]){
                q.push(parent[temp]) ;
                mp[parent[temp]] = true ;
            }
        }

        
    }

    return time ;
}
