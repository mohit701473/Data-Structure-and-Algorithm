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


vector<int> node_to_root_path(Node* node, int val){
    if(node -> data == val){
        return {val} ;
    }

    for(auto child: node -> children){
        vector<int> temp = node_to_root_path(child, val) ;
        if(!temp.empty()){
            temp.push_back(node -> data) ;
            return temp ;
        }
    }

    return {} ;
}

int lowest_common_ancestor(Node* root, int num1, int num2){

    vector<int> path1 = node_to_root_path(root, num1) ;
    vector<int> path2 = node_to_root_path(root, num2) ;
    if(path1.empty() || path2.empty()){
        return -1 ;
    }

    int lca ;
    int i = path1.size() - 1, j = path2.size() - 1;

    while(i >=0 && j >= 0){
        if(path1[i] != path2[j])
            return path1[i+1] ;

        i--, j-- ;
    }

    return path1[0] ;
}

int distance_between_nodes_edgesWise(Node* root, int num1, int num2){

    vector<int> path1 = node_to_root_path(root, num1) ;
    vector<int> path2 = node_to_root_path(root, num2) ;

    if(path1.empty() || path2.empty()){
        return -1 ;
    }

    int lca ;
    int i = path1.size() - 1, j = path2.size() - 1;

    while(i >=0 && j >= 0 && path1[i] == path2[j]){
        i--, j-- ;
    }
    
    i++ ;
    j++ ;

    return i + j ; 
}

int main(){
    vector<int> inputArray = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1} ;
    int n = inputArray.size() ;
    Node* root = buildTree(inputArray, n) ;

    vector<int> path = node_to_root_path(root, 120) ;
    if(path.size() == 0){
        cout << "No path exist" << endl ;
    }

    for(int i=0 ; i<path.size() ; i++){
        cout << path[i] << " " ;
    }cout << endl ;


    cout << lowest_common_ancestor(root, 120, 110) << endl ;

    cout << distance_between_nodes_edgesWise(root, 120, 30) << endl ;


}