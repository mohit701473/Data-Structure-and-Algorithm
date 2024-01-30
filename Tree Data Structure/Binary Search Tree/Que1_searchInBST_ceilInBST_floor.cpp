// LeetCode -> 700. Search in a Binary Search Tree
https://leetcode.com/problems/search-in-a-binary-search-tree/description/


// T.C. = O(log(N))
// S.C. = O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root ;
        while(curr != NULL){
            if(curr -> val == val) return curr ;
            curr = (curr -> val < val) ? curr -> right : curr -> left ;
        }

        return curr ;
    }
};




// Code Studio ->  Ceil from BST
https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

// T.C. = O(2log(N))
// S.C. = O(1)
int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1 ;
    BinaryTreeNode<int> *curr = node ;

    while(curr != NULL){
        if(curr -> data >= x)
            ceil = curr -> data ;

        curr = (curr -> data < x) ? curr -> right : curr -> left ;
    }

    return ceil;
}



// T.C. = O(2log(N))
// S.C. = O(1)
int Floor(BinaryTreeNode<int> *node, int input)
{
	int ans = -1 ;
	while(node){
		if(node -> data == input)
			return ans = node -> data ;

		if(node -> data < input){
			ans = node -> data ;
			node = node -> right ;
		}
		else{
			node = node -> left ;
		}
	}

	return ans ;
}
