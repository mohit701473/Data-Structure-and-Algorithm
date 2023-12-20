#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    vector<Node*> children ;
};

Node* newNode(int val){
    Node* temp = new Node ;
    temp -> data = val ;
    return temp ;
}


Node* buildTree(vector<int> &inputArray, int size){
    Node* root = NULL ;
    stack<Node*> st ;

    for(int i=0 ; i<size ; i++){
        if(inputArray[i] == -1){
            st.pop() ;
        }
        else{
            Node* temp = newNode(inputArray[i]) ;
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

void displayEulearTreePath(Node* node){
    cout<< node -> data << " -> " ;

    for(Node* child: node->children){
        cout<< child -> data << ", " ;
    }
    
    cout << endl ;

    for(Node* child: node -> children){
        displayEulearTreePath(child) ;
    }
}


int main()
{
    //cout<<"inside main"<<endl; 
    vector<int> inputArray = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n = inputArray.size() ;
    Node *root = buildTree(inputArray, n) ;
    displayEulearTreePath(root) ;
}