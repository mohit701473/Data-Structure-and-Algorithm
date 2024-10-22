/*
 * Codeforces Round 742 (Div. 2) -> E. Non-Decreasing Dilemma
 * https://codeforces.com/contest/1567/problem/E
 * 
 * Accepted 
 */

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Node {
public:
    ll cnt, first_ele, last_ele;
    ll total_ele, first_total, last_total;

    Node(ll c, ll f, ll l, ll t, ll f_t, ll l_t) {
        this -> cnt = c;
        this -> first_ele = f;
        this -> last_ele = l;
        this -> total_ele = t;
        this -> first_total = f_t;
        this -> last_total = l_t;
    }

    Node() {
        this -> cnt = 0;
        this -> first_ele = 0;
        this -> last_ele = 0;
        this -> total_ele = 0;
        this -> first_total = 0;
        this -> last_total = 0;
    }
};

Node merge(Node left, Node right) {
    Node ansNode;
    if (left.last_ele <= right.first_ele) {
        ansNode.cnt = left.cnt + right.cnt + left.last_total * right.first_total;
        ansNode.first_total = (left.first_total == left.total_ele) ? (left.first_total + right.first_total) : left.first_total;
        ansNode.last_total =(right.last_total == right.total_ele) ? (right.last_total + left.last_total) : right.last_total;
    } else {
        ansNode.cnt = left.cnt + right.cnt;
        ansNode.first_total = left.first_total;
        ansNode.last_total = right.last_total;
    }

    ansNode.first_ele = left.first_ele;
    ansNode.last_ele = right.last_ele;
    ansNode.total_ele = left.total_ele + right.total_ele;
    
    return ansNode;
}

void buildSegmentTree(ll idx, ll low, ll high, ll arr[], Node seg[]) {
    if (low == high) {
        seg[idx] = Node(1, arr[low], arr[low], 1, 1, 1);
        // cout << "low: " << low << " high: " << high << " cnt: " << seg[idx].cnt << endl;
        return;
    }

    ll mid = low + (high - low) / 2;
    buildSegmentTree(idx * 2 + 1, low, mid, arr, seg);
    buildSegmentTree(idx * 2 + 2, mid + 1, high, arr, seg);
    seg[idx] = merge(seg[idx *2 + 1], seg[idx * 2 + 2]);
    // cout << "low: " << low << " high: " << high << " cnt: " << seg[idx].cnt << endl;
}

void updateSegmentTree(ll idx, ll low, ll high, ll i, ll val, Node seg[]) {
    if (low == high) {
        seg[idx] = Node(1, val, val, 1, 1, 1);
        return;
    }

    ll mid = low + (high - low) / 2;
    if (i <= mid) updateSegmentTree(idx * 2 + 1, low, mid, i, val, seg);
    else updateSegmentTree(idx * 2 + 2, mid + 1, high, i, val, seg);
    seg[idx] = merge(seg[idx *2 + 1], seg[idx * 2 + 2]);
}

Node queryInSegmentTree(ll idx, ll low, ll high, ll l, ll r, Node seg[]) {
    // no overlasp
    if (r < low || l > high)
        return Node();
    
    // complete overlap
    if (l <= low && r >= high)
        return seg[idx];

    // partial overlap
    ll mid = low + (high - low) / 2;
    Node left  = queryInSegmentTree(idx * 2 + 1, low, mid, l, r, seg);
    Node right = queryInSegmentTree(idx * 2 + 2, mid + 1, high, l, r, seg);
    return merge(left, right);
}

void solve() {
    // cout << "---- Working enter t -----" << endl;
    // ll t;
    // cin >> t;
    // while(t--) {
        ll n, q;
        cin >> n >> q;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        Node seg[4 * n];
        buildSegmentTree(0, 0, n-1, arr, seg);
        while(q--) {
            ll type;
            cin >> type;
            if (type == 1) {
                ll i, val;
                cin >> i >> val;
                i--;
                updateSegmentTree(0, 0, n-1, i, val, seg);
            } else {
                ll l, r;
                cin >> l >> r;
                l--, r--;
                Node ans = queryInSegmentTree(0, 0, n-1, l, r, seg);
                cout << ans.cnt << endl;
            }
        }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);  // Faster I/O
    cin.tie(nullptr);  // Disable I/O synchronization
    solve();
}