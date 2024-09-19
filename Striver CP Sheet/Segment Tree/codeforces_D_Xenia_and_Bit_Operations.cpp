#include<bits/stdc++.h>
using namespace std;

class SEGTree {
public:
    vector<int> seg;

    SEGTree(int size) {
        seg = vector<int> (size, 0);
    }

    void buildSegmentTree(int idx, int low, int high, vector<int> &arr, bool orr) {
        if (low == high) {
            this -> seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        buildSegmentTree(idx * 2 + 1, low, mid, arr, !orr);
        buildSegmentTree(idx * 2 + 2, mid + 1, high, arr, !orr);

        if (orr) this -> seg[idx] = seg[idx * 2 + 1] | seg[idx * 2 + 2];
        else this -> seg[idx] = seg[idx * 2 + 1] ^ seg[idx * 2 + 2];
    }

    void updateSegmentTree(int idx, int low, int high, int i, int val, bool orr) {
        if (low == high) {
            this -> seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        bool l = false, r = false;
        if (i <= mid) updateSegmentTree(idx * 2 + 1, low, mid, i, val, !orr);
        else updateSegmentTree(idx * 2 + 2, mid + 1, high, i, val, !orr);

        if (orr) this -> seg[idx] = seg[idx * 2 + 1] | seg[idx * 2 + 2];
        else this -> seg[idx] = seg[idx * 2 + 1] ^ seg[idx * 2 + 2];
        // orr = 1 -> OR
        // orr = 0 -> XOR
    }
};

int main() {
    // cout << "----- Enter Input -----" << endl;
    // int t;
    // cin >> t;
    // while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(1 << n);
        // cout << "Working--1" << endl;
        for (int i = 0; i < (1 << n); i++)
            cin >> arr[i];
        // cout << "Working--2" << endl;
        SEGTree seg1(2 * (1 << n) - 1);
        bool flag = true;
        seg1.buildSegmentTree(0, 0, (1 << n) - 1, arr, (n % 2));
        // for (int i = 0; i < seg1.seg.size(); i++)
        //     cout << seg1.seg[i] << " ";
        // cout << endl;
        for (int j = 0; j < m; j++) {
            int i, val;
            cin >> i >> val;
            seg1.updateSegmentTree(0, 0, (1 << n) - 1, i-1, val, (n % 2));
            cout << seg1.seg[0] << endl;
            // cout << "Working--3" << endl;
        }
    // }
}