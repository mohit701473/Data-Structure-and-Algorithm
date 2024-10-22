#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, q, type, l, r, x_or;
int arr[N+1], seg[4*N+1];
int lazy[4*N+1] = {0};
// vector<int> lazy(4*N+1, 0);


int distributeXorOverSum(int a, int b, int XOR) {

}

void propaget(int idx, int int low, int high) {
    if (lazy[idx] != 0)
        return;

    if (low == high) {
        seg[idx] ^= lazy[idx];
        return;
    }

    int a = seg[idx * 2];
    int b = seg[idx * 2 + 1];
}

void build(int idx, int low, int high) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }

    int mid = (high + low) >> 1;
    build(idx * 2, low, mid);
    build(idx * 2 + 1, mid + 1, high);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void update(int idx, int low, int high, int l, int r, int x_or) {
    // update the previous remaining updates and propagets downward
    if (lazy[idx] != 0) {
        seg[idx] ^= lazy[idx];
        // propagets update downward
        if (low != high) {
            lazy[idx * 2] ^=  lazy[idx];
            lazy[idx * 2 + 1] ^= lazy[idx];
        }
        lazy[idx] = 0;
    }

    // no overlap
    if (r < low || l > high)
        return;
        
    // complete overlap
    if (l <= low && r >= high) {
        seg[idx] ^= x_or;
        // if leaf nodes there then set there lazy value
        if(low != high) {
            lazy[idx * 2] ^= x_or;
            lazy[idx * 2 + 1] ^= x_or;
        }
        return;
    }

    int mid = (high + low) >> 1;
    update(idx * 2, low, mid, l, r, x_or);
    update(idx * 2 + 1, mid + 1, high, l, r, x_or);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int query(int idx, int low, int high, int l, int r) {
    // update the previous remaining updates and propagets downward
    if (lazy[idx] != 0) {
        seg[idx] ^= lazy[idx];
        // propagets update downward
        if (low != high) {
            lazy[idx * 2] ^= lazy[idx];
            lazy[idx * 2 + 1] ^= lazy[idx];
        }

        lazy[idx] = 0;
    }

    // no overlap
    if (r < low || l > high)
        return 0;

    // complete overlap
    if (l <= low && r >= high)
        return seg[idx];

    int mid = (high + low) >> 1;
    int left = query(idx * 2, low, mid, l, r);
    int right = query(idx * 2 + 1, mid + 1, high, l, r);
    return left + right;
}

int main() {
    cout <<"Running" << "\n";
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) {
            cout << query(1, 1, n, l, r) << "\n";
        } else {
            cin >> x_or;
            update(1, 1, n, l, r, x_or);
        }
    }

    return 0;
}
