#include<bits/stdc++.h>
using namespace std ;

void print(set<string> &s){

    for(auto it: s){  // T.C. = O(nlog(n))
        cout<<it<<endl;
    }cout<<endl;

    for(auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<endl;
    }cout<<endl;
}

int main()
{
    set<string> s ; // Decleration of set and this is a ordered set and store values in sorted order and only unique valuse will be stored



// ----------------------------------------------  Different Operations & Functions in set  ----------------------------------------------------------- 


// (1) Insertion in set
    // there is only one method (s.insert(key)) to insert a key inset unlike in map we have map.insert, m[key] = value 
    // Way -> 1: setName.insert(key)
    s.insert("abc") ;  // T.C. = O(log(n))  for inserting an element in ordered set bcz inmplementation of ordered ste/set is done by Red Black Tree
    s.insert("zxc") ;
    s.insert("bcv") ;
    s.insert("abc") ;


// (2) Serach key in set
    auto it = s.find("abc") ; // T.C. = O(log(n))  for finding an element in ordered ste & this find function will give the itrator(i.e pointer) corrosponding to the key

    if(it != s.end()) {  // Bcz in s.find(value) if value is not preseen then this function will return end itrator of the set and without if condition this will give segmentation fault
        cout<<(*it)<<endl;
        s.erase(it) ; // T.C. = O(log(n)) 
        // s.erase("abc")  also write as this 
    }cout<<endl;



// (3) erase key from set
    // s.erase(key) or s.erase(itrator) i.e this erase function can take key and itrator to the key
    s.erase(it) ; // T.C. = O(log(n)) 
    // s.erase("abc")  also write as this 

    print(s) ;
}