#include<iostream>
using namespace std ;

class Complex{
private:
    int a, b ;
public:
    void set_data(int, int) ;

    void show_data(){
        cout << a << " " << b << endl ;
    }

    Complex add(Complex c){
        Complex temp ;
        temp.a = a + c.a ;
        temp.b = b + c.b ;

        return temp ;
    }
};


void Complex :: set_data(int x, int y){
    a = x ; b = y ;
}

int main()
{
    Complex c1, c2, c3 ;
    c1.set_data(3, 5) ;
    c2.set_data(4, 8) ;
    //  c3 = c1 + c2 ;
    c3 = c1.add(c2) ;
    c3.show_data() ;
}