#include <iostream>
using namespace std;

int ncr[5001][5001];
int p = 1e9 + 7;

void nCr(int N, int R) {
    ncr[0][0] = 0;
    ncr[1][1] = 1;
    for (int n = 1; n <= N; n++)
        ncr[n][0] = 1;

    for (int n = 2; n <= N; n++) {
        for (int r = 1; r <= n; r++) {
            ncr[n][r] = (ncr[n-1][r] + ncr[n-1][r-1]) % p;
        }
    }
}

int main() {
    int n, r;
    cout << "Enter n and r\n";
    cin >> n >> r;
    nCr(n, r);
    cout << ncr[n][r];
}