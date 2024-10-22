#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 3e5 + 3;
ll arr[N], seg[4 * N], D[4 * N], mx[4 * N];
ll n, q, type, l, r;

void buildSegmentTree(ll idx, ll low, ll high) {
    if (low == high) {
        seg[idx] = mx[idx] = arr[low];
        return;
    }

    ll mid = low + (high - low) / 2;
    buildSegmentTree(idx * 2 + 1, low, mid);
    buildSegmentTree(idx * 2 + 2, mid + 1, high);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    mx[idx]  = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

void updateSegmentTree(ll idx, ll low, ll high, ll l, ll r) {
    // no overlap
    if (r < low || l > high)
        return;
    
    if (mx[idx] <= 2)
        return;

    // complete overlap with single element
    if (l <= low && r >= high && low == high) {
        seg[idx] = mx[idx] = D[ mx[idx]];
        return;
    }

    // partial overlap
    ll mid = low + (high - low) / 2;
    if (seg[idx * 2 + 1] > 2) updateSegmentTree(idx * 2 + 1, low, mid, l, r);
    if (seg[idx * 2 + 2] > 2) updateSegmentTree(idx * 2 + 2, mid + 1, high, l, r);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    mx[idx]  = max(mx[idx * 2 + 1], mx[idx * 2 + 2]);
} 

ll queryInSegmentTree(ll idx, ll low, ll high, ll l, ll r) {
    // no overlap
    if (r < low || l > high)
        return 0;

    // complete overlap
    if (l <= low && r >= high)
        return seg[idx];
    
    // partial overlap
    ll mid = low + (high - low) / 2;
    ll left  = queryInSegmentTree(idx * 2 + 1, low, mid, l, r);
    ll right = queryInSegmentTree(idx * 2 + 2, mid + 1, high, l, r);
    return left + right;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (ll i=1;i<=1e6;i++) {
        for (ll j=i;j<=1e6;j+=i) {
            D[j]++;
        }
    }
    
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    buildSegmentTree(0, 0, n-1);

    while (q--) {
        cin >> type >> l >> r;
        l--, r--;
        if (type == 1)
            updateSegmentTree(0, 0, n-1, l, r);
        else cout << queryInSegmentTree(0, 0, n-1, l, r) << endl;
    }

    return 0;
}