// GFG ->Is Binary Tree Heap
// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1


class Solution {
  public:
    int countNode(struct Node* tree) {
        if(tree == NULL)
            return 0;
            
        int l = countNode(tree -> left);
        int r = countNode(tree -> right);
        
        return 1 + l + r;
    }
  
    bool isMaxHeap(struct Node* tree) {
        if(tree == NULL)
            return true;
            
        if(tree -> left != NULL && tree -> left -> data > tree -> data)
            return false;
            
        if(tree -> right != NULL && tree -> right -> data > tree -> data)
            return false;
        
        bool l = isMaxHeap(tree -> left);
        bool r = isMaxHeap(tree -> right);
        
        return (l && r);
    }
    
    bool isCBT(struct Node* tree, int i, int n) {
        if(tree == NULL)
            return true;
            
        if(i >= n)
            return false;
        
        bool l = isCBT(tree -> left, 2*i+1, n);
        bool r = isCBT(tree -> right, 2*i+2, n);
        
        return (l && r);
    }
    
    bool isHeap(struct Node* tree) {
        int n = countNode(tree); 
        return (isCBT(tree, 0, n) && isMaxHeap(tree));
    }
};