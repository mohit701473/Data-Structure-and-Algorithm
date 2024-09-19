#include<bits/stdc++.h>
using namespace std;

/*
 * arr is the given array on which u have to apply queries
 * n = arr.size(); lenght of the arr
 * low  = 0; first index of the arr
 * high = n-1; last index of the arr
 * 4 * n is the size of the segment tree which have a 
 * large proof i.e. why the size of segement tree is 4 * n
 * idx is the segment tree index 
 * l and r is the query range
 */

void build(int idx, int low, int high, int arr[], int seg[]) {
    if (low == high) {
        sge[idx] = arr[low];
        return ;
    }

    int mid = low + (high - low) / 2;
    build(idx*2+1, low, mid, arr, seg);
    build(idx*2+2, mid+1, high, arr, seg);
    seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
}

int query(int idx, int low, int high, int l, int r, int seg[]) {
    // no overlap
    if (r < low || high < l)
        return INT_MAX;

    // complete overlap
    if (l <= low && r >= high)
        return seg[idx];

    // partial overlap
    int mid   = low + (high - low) / 2;
    int left  = query(idx*2+1, low, mid, l, r, seg);
    int right = query(idx*2+2, mid+1, high, l, r, seg);
    return min(left, right);
}

voio update(int idx, int low, int high, int i, int val, int seg[]) {
    if (low == high) {
        seg[idx] = val;
        return;
    }
    
    int mid = low + (high - low) / 2;
    if (i <= mid)
        update(idx*2+1, low, mid, i, val, seg);
    else update(idx*2+2, mid+1, high, i, val, seg);
    seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int seg[4 * n];
        build(0, 0, n-1, arr, seg);
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r;
                cin >> l >> r;
                cout << query(0, 0, n-1, l, r, seg) << " ";
            }
            else {
                int i, val;
                cin >> i >> val;
                cout << update(0, 0, n-1, i, val, seg);
            }
        }
    }
}