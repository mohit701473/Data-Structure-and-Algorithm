// Codeing Ninja ->  Predecessor And Successor In BST
https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049


// T.C. = O(N)
// S.C. = O(1)
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int successor = -1 ;
    TreeNode* curr = root ;
    while(curr){
        if(curr -> data > key){
            successor = curr -> data ;
            curr = curr -> left ;
        }
        else{
            curr = curr -> right ;
        }
    }

    int predecessor = -1 ;
    curr = root ;
    while(curr){
        if(curr -> data < key){
            predecessor = curr -> data ;
            curr = curr -> right ;
        }
        else{
            curr = curr -> left ;
        }
    }

    return {predecessor, successor} ;
}