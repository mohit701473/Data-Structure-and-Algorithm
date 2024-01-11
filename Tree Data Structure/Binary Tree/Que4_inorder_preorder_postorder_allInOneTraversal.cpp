// Approch 1 -> Itrative solution
// T.C. = O(3n) because every node of tree is visited 3 times in loop
// S.C. = O(3n) or O(4n) 
vector<vector<int>> getTreeTraversal(TreeNode *root){

    vector<int> preorder, inorder, postorder ;
    stack<pair<TreeNode*, int>> st ;
    st.push({root, 1}) ;

    while(!st.empty()){
        pair<TreeNode*, int> p = st.top() ;
        st.pop() ;
        int num = p.second ;

        if(num == 1){
            preorder.push_back(p.first -> data) ;
            p.second++ ;
            st.push(p) ;

            if(p.first -> left != NULL){
                st.push({p.first -> left, 1}) ;
            }

        }
        else if(num == 2){
            inorder.push_back(p.first -> data) ;
            p.second++ ;
            st.push(p) ;

            if(p.first -> right != NULL){
                st.push({p.first -> right, 1}) ;
            }
        }
        else{ // num == 3
            postorder.push_back(p.first -> data) ;
        }
    }

    vector<vector<int>> allTraversal ;
    allTraversal.push_back(inorder) ;
    allTraversal.push_back(preorder) ;
    allTraversal.push_back(postorder) ;

    return allTraversal ;
}