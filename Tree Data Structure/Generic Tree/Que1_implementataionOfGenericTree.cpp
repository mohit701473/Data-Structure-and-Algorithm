#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    vector<Node*> children ;

    // constructor
    Node(int val){
        data = val ;
        //cout << "children size: "<< children.size() << endl ;
    }
};


Node* buildTree(vector<int> &inputArray, int size){
    Node* root = NULL ;
    stack<Node*> st ;

    for(int i=0 ; i<size ; i++){
        if(inputArray[i] == -1){
            st.pop() ;
        }
        else{
            Node* temp =  new Node(inputArray[i]) ;
            if(st.size() == 0){
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

void displayTree(Node* node){
    cout<< node -> data << " -> " ;

    for(Node* child: node->children){
        cout<< child -> data << ", " ;
    }
    
    cout << endl ;

    for(Node* child: node -> children){
        displayTree(child) ;
    }
}

void sizeOfGenericTree(Node* node, int &countNode){

    if(node == NULL){
        return ;
    }

    countNode += 1 ;

    for(Node* child: node -> children){
        sizeOfGenericTree(child, countNode) ;
    }
}

int numberOfNodesInGenericTree(Node* node){

    if(node == NULL){
        return 0 ;
    }

    int countNumberOfNodesInSubtree  = 0 ;

    for(Node* child: node -> children){
        countNumberOfNodesInSubtree += numberOfNodesInGenericTree(child) ;
    }

    return countNumberOfNodesInSubtree + 1 ; // 1 is added because root node of the subtree is included
}

void maximumInTree1(Node* node, int &maxi){

    if(node == NULL){
        return ;
    }

    if(node -> data > maxi){
        maxi = node -> data ;
    }

    for(Node* child: node -> children){
        maximumInTree1(child, maxi) ;
    }

}

int maximumInTree2(Node* node){

    if(node == NULL){
        return INT_MIN ;
    }

    int maxi = node -> data ;

    for(Node* child: node -> children){
        int subtreeMaxi = maximumInTree2(child) ;
        maxi = max(maxi, subtreeMaxi) ;
    }

    return maxi ;
}

// hieght of the tree edges wise i.e. how far is the leaf node from the root node according to edges
int heightOrDepthOfTree(Node* node){

    if(node == NULL || node -> children.size() == 0){ // no node or leaf node 
        return 0 ;
    }

    int depth = 0 ;

    for(Node* child: node -> children){
        int subtreeDepth = heightOrDepthOfTree(child) ;
        depth = max(depth, subtreeDepth) ;
    }

    return depth + 1 ; 
}

int main()
{
    vector<int> inputArray = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n = inputArray.size() ;
    Node *root = buildTree(inputArray, n) ;
    displayTree(root) ;


    int countNode = 0 ;
    sizeOfGenericTree(root, countNode) ;
    cout<<"Size of the tree is: "<< countNode << endl ;
    cout<<"Size of the tree is: "<< numberOfNodesInGenericTree(root) << endl ;

    int maxi = INT_MIN ;
    maximumInTree1(root, maxi) ;
    cout<<"Maximum in the tree is: "<< maxi << endl ;
    cout<<"Maximum in the tree is: "<< maximumInTree2(root) << endl ;

    cout<<"Height or Depth of the tree is: "<< heightOrDepthOfTree(root) << endl ;


}