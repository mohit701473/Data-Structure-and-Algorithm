/*
Important: While we are solving problems using recusrion then our thinking is like that recursion always
            return the answre that we want but in actul it is not like that because their are some problems
            in which have to find siomething else and we resturn something else from recursion.
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


// It is a travel and change typr problem in which we travel the tree and change the variables according the
// some condition.
int calculateMaximumSumSubtree_returnSumOfTree(Node* node, int &maxSum, int &maxSumNode){
    int sum = 0 ;

    for(Node* child: node -> children){
        int childSum = calculateMaximumSumSubtree_returnSumOfTree(child, maxSum, maxSumNode) ;
        sum += childSum ;
    }

    sum += node -> data ; 

    if(sum > maxSum){
        maxSum = sum ;
        maxSumNode = node -> data ;
    }

    return sum ;
}



int calculateDiameterReturnHeight(Node* node, int &dia){
    int dch = -1 ; // dch = dipest child height
    int sdch = -1 ; // sdch = second dipest child height

    for(Node* child: node -> children){
        int ht = calculateDiameterReturnHeight(child, dia) ;

        if(ht > dch){
            sdch = dch ;
            dch = ht ;
        }
        else if(ht > sdch){
            sdch = ht ;
        }

        dia = max(dia, (dch + sdch + 2)) ;
    }

    return dch + 1 ;
}



int main(){
    vector<int> inputArray1 = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1} ;
    int n1 = inputArray1.size() ;
    Node* root1 = buildTree(inputArray1, n1) ;

    int maxSum = INT_MIN ;
    int maxSumNode = -1 ;

    calculateMaximumSumSubtree_returnSumOfTree(root1, maxSum, maxSumNode) ;

    cout << maxSumNode << " " << maxSum << endl ;

    int dia = INT_MIN ;
    calculateDiameterReturnHeight(root1, dia) ;
    cout << dia << endl ;
}