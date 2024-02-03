// Coding Ninja -> Size of Largest BST in Binary Tree
https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_893103



// T.C. = O(N)
// S.C. = O(1)
class NodeValue{
    public:
    int maxNode, minNode, maxSize ;
    
    NodeValue(int minNode, int maxNode , int maxSize){
        this -> maxNode = maxNode ;
        this -> minNode = minNode ;
        this -> maxSize = maxSize ;
    }
};

NodeValue postorder(TreeNode* node){
    // node == NULL
    if(!node){
        return NodeValue(INT_MAX, INT_MIN, 0) ;
    }

    auto l = postorder(node -> left) ;
    auto r = postorder(node -> right) ;

    if(l.maxNode < node -> data && node -> data < r.minNode){
        return NodeValue(min(node -> data, l.minNode), max(node -> data, r.maxNode), l.maxSize + r.maxSize + 1) ;
    }

    return NodeValue(INT_MIN, INT_MAX, max(l.maxSize, r.maxSize)) ;
}


int largestBST(TreeNode * root){
    return postorder(root).maxSize ;
}