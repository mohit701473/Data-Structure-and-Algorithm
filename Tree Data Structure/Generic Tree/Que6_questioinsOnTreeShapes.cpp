/*
Que 1 -> Are tree same in shape
Que 2 -> Are tree mirror in shape
Que 3 -> Is tree symmetric in shape
*/

#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    vector<Node*> children ;

    //constructor
    Node(int val){
        this -> data = val ;
    }
};

Node* buildTree(vector<int> &inputArray, int n){
    Node* root = NULL ;
    stack<Node*> st ;

    for(int i=0 ; i<n ; i++){
        if(inputArray[i] == -1){
            st.pop() ;
        }
        else{
            // step -> 1: create node for the data
            Node* node = new Node(inputArray[i]) ;

            // step -> 2: now is node ka parent dekho or root node h to root node bna do ese
            if(st.empty()){ // stack is empty that means this is a root node
                root = node ;
            }
            else{ // stack is not empty that meas top of teh stack is teh parent of the node
                Node* parent = st.top() ;
                parent -> children.push_back(node) ; 
            }

            st.push(node) ;
        }
    }

    return root ;
}

bool are_tree_similiar_in_shape(Node* node1, Node* node2){
    if(node1 -> children.size() != node2 -> children.size()){
        return false ;
    }

    bool ans = true ;
    int size = node1 -> children.size() ;

    for(int i = 0; i<size ; i++){
        Node* ch1 = node1 -> children[i] ;
        Node* ch2 = node2 -> children[i] ;

        bool res = are_tree_similiar_in_shape(ch1, ch2) ;
        ans = ans & res ;

        if(!ans){
            return ans ;
        }
    }

    return ans ; 
}

bool are_tree_mirror_in_shape(Node* node1, Node* node2){
    if(node1 -> children.size() != node2 -> children.size()){
        return false ;
    }

    int size = node1 -> children.size() ;
    
    for(int i=0 ; i<size ; i++){
        Node* ch1 = node1 -> children[i] ;
        Node* ch2 = node2 -> children[size-i-1] ;

        if(are_tree_mirror_in_shape(ch1, ch2) == false){
            return false ;
        }
    }

    return true ;
}

void mirrorOfGenericTree(Node* node){
    if(node == NULL) return ;

    for(Node* child: node -> children){
        mirrorOfGenericTree(child) ;
    }

    reverse(node -> children.begin(), node -> children.end()) ;
}

bool are_tree_symmetric(Node* node){
    return are_tree_mirror_in_shape(node, node) ;
}


int main(){
    vector<int> inputArray1 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n1 = inputArray1.size() ;
    Node* root1 = buildTree(inputArray1, n1) ;

    vector<int> inputArray2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n2 = inputArray2.size() ;
    Node* root2 = buildTree(inputArray2, n2) ;
    

    cout << are_tree_similiar_in_shape(root1, root2) << endl ;

    mirrorOfGenericTree(root2) ;

    cout << are_tree_mirror_in_shape(root1, root2) << endl ;

    cout << are_tree_symmetric(root1) << endl ;
    

}