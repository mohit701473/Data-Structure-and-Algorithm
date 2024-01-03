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

void mirrorOfGenericTree(Node* node){
    if(node == NULL) return ;

    for(Node* child: node -> children){
        mirrorOfGenericTree(child) ;
    }

    reverse(node -> children.begin(), node -> children.end()) ;
}

void removeLeafesNodesFormGenericTree(Node* node){

    if(node == NULL) return ;

    for(int i = node -> children.size() - 1 ; i>=0 ; i--){
        Node* child = node -> children[i] ;
        if(child -> children.size() == 0){
            // vector<Node*>::iterator it ;
            // it = node -> children.begin() + i ;
            auto it = node -> children.begin() + i ;
            node -> children.erase(it) ;
        }
    }

    for(Node* child: node -> children){
        removeLeafesNodesFormGenericTree(child) ;
    }
}


int main()
{
    vector<int> inputArray = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n = inputArray.size() ;
    Node *root = buildTree(inputArray, n) ;

    mirrorOfGenericTree(root) ;
    levelOrderTraversalLevlWise_usingOneQueue(root) ;

    removeLeafesNodesFormGenericTree(root) ;
    levelOrderTraversalLevlWise_usingOneQueue(root) ;
}