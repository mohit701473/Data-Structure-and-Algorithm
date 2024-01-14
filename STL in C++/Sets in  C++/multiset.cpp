#include<bits/stdc++.h>
using namespace std ;

void print(multiset<string> &s){

    for(auto it: s){  // T.C. = O(nlog(n))
        cout<<it<<endl;
    }cout<<endl;

    for(auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<endl;
    }cout<<endl;
}

int main()
{
// Multiset allows us to insert multiple keys unlike set will store unique keys only and multiset implementation si also done using red black tree

    // Decleration of multiset
    multiset<string> s ; 

    s.insert("abc") ;  // T.C. = O(log(n))  for inserting an element in  multiset
    s.insert("zxc") ;
    s.insert("bcv") ;
    s.insert("abc") ;

    auto it = s.find("abc") ; // T.C. = O(log(n))  for finding an element in multiset

    // In multiset find() function will give the itrator of 1st duplicate value

    if(it != s.end()) {  // Bcz in s.find(value) if value is not preseen then this function will return end itrator of the set and without if condition this will give segmentation fault
        cout<<(*it)<<endl;
        s.erase(it) ; // T.C. = O(log(n)) 
        // s.erase("abc")  also write as this and this will erase all duplicate value 
        // erase(it)  function will erase 1st find value
        
    }cout<<endl;


    print(s) ;
}