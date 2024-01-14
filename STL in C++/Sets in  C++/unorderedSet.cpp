#include<bits/stdc++.h>
using namespace std ;

void print(unordered_set<string> &s){

    for(auto it: s){  // T.C. = O(n)  of this loop
        cout<<it<<endl;
    }cout<<endl;

    for(auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<endl;
    }cout<<endl;
}

int main()
{
    unordered_set<string> s ; // Decleration of unordered set and this store values in random order

    s.insert("abc") ;  // T.C. = O(1)  for inserting an element in unordered set
    s.insert("zxc") ;
    s.insert("bcv") ;
    s.insert("abc") ;

    auto it = s.find("abc") ; // T.C. = O(1)  for finding an element in unordered ste

    if(it != s.end()) {  // Bcz in s.find(value) if value is not preseen then this function will return end itrator of the set and without if condition this will give segmentation fault
        cout<<(*it)<<endl;
        s.erase(it) ; // T.C. = O(1) 
        // s.erase("abc")  also write as this 
    }cout<<endl;


    print(s) ;
}