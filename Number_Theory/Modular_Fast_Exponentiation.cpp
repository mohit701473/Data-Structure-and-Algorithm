#include <iostream>
using namespace std;

int exponent(long x, long n, long m) {
    long ans = 1;

    while (n > 0) {
        if (n % 2) { // n is odd
            ans = (ans * x) % m;
            n--;
        }

        x = (x * x) % m;
        n = n / 2; // here we r not doing mod with n bcz humne pure code me
                   //khi pr bhi n ka mod nhi kiya h
    }

    return ans;
}

int main() {
    int x, n;
    int m = 1e9 + 7;

    cout << "Enter x and n\n";
    cin >> x >> n;

    cout << exponent(x, n, m);
}