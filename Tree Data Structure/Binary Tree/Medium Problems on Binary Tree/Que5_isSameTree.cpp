// Approch -> recursive preorder
// T.C. = O(H) ~~ O(N)
// S.C. = O(H) ~~ O(N)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true ;
        }

        if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            return false ;
        }

        if(p -> val != q -> val)
            return false ;

        int l = isSameTree(p -> left, q -> left) ;
        int r = isSameTree(p -> right , q -> right) ;

        return (l & r) ;
    }
};