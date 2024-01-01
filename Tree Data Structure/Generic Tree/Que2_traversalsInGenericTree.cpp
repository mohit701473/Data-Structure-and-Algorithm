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

void levelOrderTraversal(Node* node){
    if(node == NULL) return ;

    // use r p a algorithm
    queue<Node*> q ;
    q.push(node) ;

    while(!q.empty()){
        // remove
        Node* temp = q.front() ;
        q.pop() ;

        // print
        cout<< temp -> data << " " ;

        // add children
        for(Node* child: temp -> children){
            q.push(child) ;
        }
    }
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

void levelOrderTraversalLevelWise_usingTowQueeu(Node* node){
    if(node == NULL) return ;

    queue<Node*> mq ;
    queue<Node*> cq ;

    mq.push(node) ;

    while(!mq.empty() || !cq.empty()){
        // remove from mq
        Node* temp = mq.front() ;
        mq.pop() ;

        // print
        cout << temp -> data << " " ;

        // add child in cq
        for(Node* child: temp -> children){
            cq.push(child) ;
        }

        if(mq.empty()){
            cout << endl ; 
            mq = cq ;
            cq = queue<Node*>() ;  // asign an empty queue to child queue "cq"
        }
    }
}

void levelOrderTraversalLevelWise_countQueueSize(Node* node){
    if(node == NULL) return ;

    queue<Node*> q ;
    q.push(node) ;

    while(!q.empty()){
        int q_size = q.size() ;

        for(int i=0 ; i<q_size ; i++){
            // reomve
            Node* temp = q.front() ;
            q.pop() ;

            // print
            cout << temp -> data << " " ;

            // add child
            for(Node* child: temp -> children){
                q.push(child) ;
            }
        }

        cout << endl ; 
    }
}

void zig_zag_levelOrderTraversal(Node* node){
    if(node == NULL) return ;

    stack<Node*> mainStack ;
    stack<Node*> childStack ;

    int level = 1 ;
    mainStack.push(node) ;

    while(!mainStack.empty() || !childStack.empty()){
        // remove
        Node* temp = mainStack.top() ;
        mainStack.pop() ;

        // print
        cout << temp -> data << " " ;

        // add child
        if(level % 2 != 0){
            for(int i=0 ; i < temp -> children.size() ; i++){
                Node* child = temp -> children[i] ;
                childStack.push(child) ;
            }
        }
        else{
            for(int i=temp -> children.size() - 1 ; i >= 0  ; i--){
                Node* child = temp -> children[i] ;
                childStack.push(child) ;
            }
        }

        if(mainStack.empty()){
            cout << endl ;
            mainStack = childStack ;
            //while(!childStack.empty()) childStack.pop() ;
            childStack = stack<Node*>() ;
            level++ ;
        }
    }
}



int main()
{
    vector<int> inputArray = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
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

    cout<< "Level order traversal is: "<< endl ;
    levelOrderTraversal(root) ;
    cout << endl ;

    cout<< "Level order traversal level wise is: "<< endl ;
    levelOrderTraversalLevlWise_usingOneQueue(root) ;
    cout << endl ;

    cout<< "Level order traversal level wise is: "<< endl ;
    levelOrderTraversalLevelWise_usingTowQueeu(root) ;
    cout << endl ;

    cout<< "Level order traversal level wise is: "<< endl ;
    levelOrderTraversalLevelWise_countQueueSize(root) ;
    cout << endl ;

    cout<< "Zig-Zag level order traversal is: "<< endl ;
    zig_zag_levelOrderTraversal(root) ;
    cout << endl ;
}