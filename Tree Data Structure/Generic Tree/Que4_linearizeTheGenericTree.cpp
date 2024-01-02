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

// level wise print level order traversal
void levelOrderTraversalLevlWise_usingOneQueue(Node* node){
    if(node == NULL) return ;

    // use r p a algorithm
    queue<Node*> q ;
    q.push(node) ;
    q.push(NULL) ;

    while(!q.empty()){
        // remove
        Node* temp = q.front() ;
        q.pop() ;

        if(temp != NULL){
            // print
            cout<< temp -> data << " " ;

            // add children
            for(Node* child: temp -> children){
                q.push(child) ;
            }
        }
        else if(!q.empty()){
            cout<<endl ;
            q.push(NULL) ;
        }
    }
}


Node* getTail(Node* node){
    //if(node == NULL) return NULL ;

    while(node -> children.size() > 0){
        node = node -> children[0] ;
    }

    return node ;

}

void linearizeThegenericTree(Node* node){

    for(Node* child: node -> children){
        linearizeThegenericTree(child) ;
    }

    while(node -> children.size() > 1){
        int idx = node -> children.size() - 1 ;

        // store the last child 
        Node* last_child = node -> children[idx] ;

        // remove the last child 
        auto it = node -> children.end() - 1 ;
        node -> children.erase(it) ;

        // get the second last child
        Node* second_last_child  = node -> children[idx-1] ;

        // now find the tail of the second last child
        Node* tail = getTail(second_last_child) ;

        // now add the last_child into the tail of the second_last_child
        tail -> children.push_back(last_child) ;
    }
}


int main()
{
    vector<int> inputArray = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n = inputArray.size() ;
    Node *root = buildTree(inputArray, n) ;

    // approch - 1
    linearizeThegenericTree(root) ;
    levelOrderTraversalLevlWise_usingOneQueue(root) ;
}