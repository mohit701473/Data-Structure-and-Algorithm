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


void ceil_floor(Node* node, int val, int &ceil, int &floor){
    if(node -> data > val){
        ceil = min(ceil, node -> data) ;
    }
    else{
        floor = node -> data != val ? max(floor, node -> data) : floor ; 
    }

    for(Node* child: node -> children){
        ceil_floor(child, val, ceil, floor) ;
    }
}

void getFloor(Node* node, int val, int &floor){
    if(node -> data < val){
        floor = max(floor, node -> data) ;
    }

    for(Node* child: node -> children){
        getFloor(child, val, floor) ;
    }
}

int KthLargest(Node* node, int k){
    //int ans ;
    int val = INT_MAX ;
    int floor = INT_MIN ;
    for(int i=1 ; i<=k ; i++){
        getFloor(node, val, floor) ;
        val = floor ;
        floor = INT_MIN ;
    }

    return val ;
}

int main(){
    vector<int> inputArray1 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n1 = inputArray1.size() ;
    Node* root1 = buildTree(inputArray1, n1) ;
    int ceil = INT_MAX ;
    int floor = INT_MIN ;
    ceil_floor(root1, 10, ceil, floor) ;

    cout << ceil << ", " << floor << endl ;

    cout << KthLargest(root1, 5) << endl ;

    

}