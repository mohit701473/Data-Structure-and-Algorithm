#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    vector<Node*> children ;
};

Node* newNode(int val){
    Node* node = new Node ;
    node -> data = val ;
    //cout<<"Size of children vector: "<< node -> children.size() << endl ;
    return node ;
}


Node* buildGenericTree(vector<int> &input, int size){

    if(size == 0) return NULL ;

    Node* root = NULL ;
    stack<Node*> st ;

    for(int i=0 ; i<size ; i++){

        if(input[i] == -1){
            st.pop() ;
        }
        else{
            Node* temp = newNode(input[i]) ; // Node is created and data is seted
            if(st.empty()){
                root = temp ;
            }
            else{
                st.top() -> children.push_back(temp) ;
            }

            st.push(temp) ;
        }

    }

    return root ;
}


void eulertraversal(Node* node){
    if(node == NULL) return ;

    // at the node's left side in the euler traversal
    cout << "Node pre: "<< node -> data << endl ;

    for(Node* child: node -> children){
        // edge's left side or edge pre
        cout << "Edge pre: " << node -> data << "--" << child -> data << endl ;

        eulertraversal(child) ;

        // edge's right side or edge post
        cout << "Edge post: " << node -> data << "--" << child -> data << endl ;
    }

    // at the node's right side in the euler traversal
    cout << "Node post: "<< node -> data << endl ;
}

void preorderTraversal(Node* node){
    if(node == NULL) return ;

    cout << node -> data << " " ;

    for(Node* child: node -> children){
        preorderTraversal(child) ;
    }
}

void postorderTraversal(Node* node){
    if(node == NULL) return ;

    for(Node* child: node -> children){
        postorderTraversal(child) ;
    }

    cout << node -> data << " " ;
}

int main()
{
    vector<int> inputArray = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1} ;
    int n = inputArray.size() ;
    Node *root = buildGenericTree(inputArray, n) ;

    cout<< "Euler Traversal is:" << endl ;
    eulertraversal(root) ;
    cout<<endl ;

    cout << "Preorder traversal of the tree is:" << endl ;
    preorderTraversal(root) ;
    cout << endl ;
 
    cout << "Postorder traversal of the tree is:" << endl ;
    postorderTraversal(root) ;
    cout << endl ;
}