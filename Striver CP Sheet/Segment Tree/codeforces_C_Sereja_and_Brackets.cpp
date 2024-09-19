// TLE
#include<bits/stdc++.h>
using namespace std;
 
class SEGTree {
public:
    vector<vector<int>> seg;
 
    SEGTree(int size) {
        seg = vector<vector<int>> (size, vector<int>(3, 0));
    }
 
    vector<int> merge(vector<int> left, vector<int> right) {
        vector<int> ans(3, 0);
        ans[0] += left[0] + right[0] + 2 * min(left[1], right[2]);
        ans[1] += left[1] + right[1] - min(left[1], right[2]);
        ans[2] += left[2] + right[2] - min(left[1], right[2]);
        return ans;
    }
 
    void buildSegmentTree(int idx, int low, int high, string &str) {
        if (low == high) {
            int i = str[low] == '(' ? 1 : 2; // '(' -> 1 & ')' -> 2;
            this -> seg[idx][i] = 1; 
            return;
        }
 
        int mid = low + (high - low) / 2;
        buildSegmentTree(idx * 2 + 1, low, mid, str);
        buildSegmentTree(idx * 2 + 2, mid + 1, high, str);
 
        seg[idx][0] += (seg[idx * 2 + 1][0] + seg[idx * 2 + 2][0] + 2 * min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
        seg[idx][1] += (seg[idx * 2 + 1][1] + seg[idx * 2 + 2][1] - min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
        seg[idx][2] += (seg[idx * 2 + 1][2] + seg[idx * 2 + 2][2] - min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
    }
 
    vector<int> query(int idx, int low, int high, int l, int r) {
        // no overlap
        if (r < low || l > high)
            return {0, 0, 0};
 
        // complete overlap
        if (l <= low && high <= r)
            return this -> seg[idx];
 
        int mid   = low + (high - low) / 2;
        vector<int> left  = query(idx * 2 + 1, low, mid, l, r);
        vector<int> right = query(idx * 2 + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
 
    void printSegmentTree() {
        for (int i = 0; i < 15; i++) {
            cout << i << ":  " << seg[i][0] << "  (:  " << seg[i][1] << "  ):  " << seg[i][2] << endl;
        }
    }
};
 
 
int main() {
    // int t;
    // cin >> t;
    // while (t--) {
        string str;
        cin >> str;
        // cout << "str: " << str << endl;
        int n = str.size();
        SEGTree seg1(4 * n);
        seg1.buildSegmentTree(0, 0, n-1, str);
        // seg1.printSegmentTree();
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            vector<int> ans = seg1.query(0, 0, n-1, l - 1, r - 1);
            cout << ans[0] << endl;
        }
    // }
}




// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// first Optimization -> TLE
#include<bits/stdc++.h>
using namespace std;
 
class SEGTree {
public:
    vector<vector<int>> seg;
 
    SEGTree(int size) {
        seg = vector<vector<int>> (size, vector<int>(3, 0));
    }
 
    vector<int> merge(vector<int> &left, vector<int> &right) {
        vector<int> ans(3, 0);
        ans[0] += left[0] + right[0] + 2 * min(left[1], right[2]);
        ans[1] += left[1] + right[1] - min(left[1], right[2]);
        ans[2] += left[2] + right[2] - min(left[1], right[2]);
        return ans;
    }
 
    void buildSegmentTree(int idx, int low, int high, string &str) {
        if (low == high) {
            int i = str[low] == '(' ? 1 : 2; // '(' -> 1 & ')' -> 2;
            this -> seg[idx][i] = 1; 
            return;
        }
 
        int mid = low + (high - low) / 2;
        buildSegmentTree(idx * 2 + 1, low, mid, str);
        buildSegmentTree(idx * 2 + 2, mid + 1, high, str);
 
        seg[idx][0] += (seg[idx * 2 + 1][0] + seg[idx * 2 + 2][0] + 2 * min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
        seg[idx][1] += (seg[idx * 2 + 1][1] + seg[idx * 2 + 2][1] - min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
        seg[idx][2] += (seg[idx * 2 + 1][2] + seg[idx * 2 + 2][2] - min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
    }
 
    vector<int> query(int idx, int low, int high, int l, int r) {
        // no overlap
        if (r < low || l > high)
            return {0, 0, 0};
 
        // complete overlap
        if (l <= low && high <= r)
            return this -> seg[idx];
 
        int mid   = low + (high - low) / 2;
        vector<int> left  = query(idx * 2 + 1, low, mid, l, r);
        vector<int> right = query(idx * 2 + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
 
    void printSegmentTree() {
        for (int i = 0; i < 15; i++) {
            cout << i << ":  " << seg[i][0] << "  (:  " << seg[i][1] << "  ):  " << seg[i][2] << endl;
        }
    }
};
 
void solve() {
    // int t;
    // cin >> t;
    // while (t--) {
        string str;
        cin >> str;
        // cout << "str: " << str << endl;
        int n = str.size();
        SEGTree seg1(4 * n);
        seg1.buildSegmentTree(0, 0, n-1, str);
        // seg1.printSegmentTree();
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            vector<int> ans = seg1.query(0, 0, n-1, l - 1, r - 1);
            cout << ans[0] << endl;
        }
    // }
}
 
int main() {
    ios_base::sync_with_stdio(false);  // Faster I/O
    cin.tie(nullptr);  // Disable I/O synchronization
    solve();
}




// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Second Optimization -> TLE
#include<bits/stdc++.h>
using namespace std;
 
class SEGTree {
public:
    vector<vector<int>> seg;
 
    SEGTree(int size) {
        seg = vector<vector<int>> (size, vector<int>(3, 0));
    }
 
    vector<int> merge(vector<int> &left, vector<int> &right) {
        vector<int> ans(3, 0);
        ans[0] += left[0] + right[0] + 2 * min(left[1], right[2]);
        ans[1] += left[1] + right[1] - min(left[1], right[2]);
        ans[2] += left[2] + right[2] - min(left[1], right[2]);
        return ans;
    }
 
    void buildSegmentTree(int idx, int low, int high, string &str) {
        if (low == high) {
            int i = str[low] == '(' ? 1 : 2; // '(' -> 1 & ')' -> 2;
            this -> seg[idx][i] = 1; 
            return;
        }
 
        int mid = low + (high - low) / 2;
        buildSegmentTree(idx * 2 + 1, low, mid, str);
        buildSegmentTree(idx * 2 + 2, mid + 1, high, str);
 
        seg[idx][0] += (seg[idx * 2 + 1][0] + seg[idx * 2 + 2][0] + 2 * min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
        seg[idx][1] += (seg[idx * 2 + 1][1] + seg[idx * 2 + 2][1] - min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
        seg[idx][2] += (seg[idx * 2 + 1][2] + seg[idx * 2 + 2][2] - min(seg[idx * 2 + 1][1], seg[idx * 2 + 2][2]));
    }
 
    vector<int> query(int idx, int low, int high, int l, int r) {
        // no overlap
        if (r < low || l > high)
            return {0, 0, 0};
 
        // complete overlap
        if (l <= low && high <= r)
            return this -> seg[idx];
 
        int mid   = low + (high - low) / 2;
        vector<int> left  = query(idx * 2 + 1, low, mid, l, r);
        vector<int> right = query(idx * 2 + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
 
    void printSegmentTree() {
        for (int i = 0; i < 15; i++) {
            cout << i << ":  " << seg[i][0] << "  (:  " << seg[i][1] << "  ):  " << seg[i][2] << endl;
        }
    }
};
 
void solve() {
    // int t;
    // cin >> t;
    // while (t--) {
        string str;
        cin >> str;
        // cout << "str: " << str << endl;
        int n = str.size();
        SEGTree seg1(4 * n);
        seg1.buildSegmentTree(0, 0, n-1, str);
        // seg1.printSegmentTree();
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            vector<int> ans = seg1.query(0, 0, n-1, l - 1, r - 1);
            cout << ans[0] << endl;
        }
    // }
}
 
int main() {
    ios_base::sync_with_stdio(false);  // Faster I/O
    cin.tie(nullptr);  // Disable I/O synchronization
    solve();
}




// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Final Optimization -> Run sucessfully
#include<bits/stdc++.h>
using namespace std;

// class SEGTree {
// public:
//     vector<vector<int>> seg;

//     SEGTree(int size) {
//         seg = vector<vector<int>> (size, vector<int>(3));
//     }

    vector<int> merge(vector<int> &left, vector<int> &right) {
        vector<int> ans(3, 0);
        ans[0] += left[0] + right[0] + 2 * min(left[1], right[2]);
        ans[1] += left[1] + right[1] - min(left[1], right[2]);
        ans[2] += left[2] + right[2] - min(left[1], right[2]);
        return ans;
    }

    void buildSegmentTree(int idx, int low, int high, string &str, int seg1[][3]) {
        if (low == high) {
            seg1[idx][0] = 0;
            seg1[idx][1] = (str[low] == '(');
            seg1[idx][2] = (str[low] == ')');
            // int i = str[low] == '(' ? 1 : 2; // '(' -> 1 & ')' -> 2;
            // this -> seg[idx][i] = 1; 
            return;
        }

        int mid = low + (high - low) / 2;
        int left_idx  = idx * 2 + 1;
        int right_idx = idx * 2 + 2;
        buildSegmentTree(left_idx, low, mid, str, seg1);
        buildSegmentTree(right_idx, mid + 1, high, str, seg1);

        int fullbracket = min(seg1[left_idx][1], seg1[right_idx][2]);

        seg1[idx][0] += (seg1[left_idx][0] + seg1[right_idx][0] + 2 * fullbracket);
        seg1[idx][1] += (seg1[left_idx][1] + seg1[right_idx][1] - fullbracket);
        seg1[idx][2] += (seg1[left_idx][2] + seg1[right_idx][2] - fullbracket);
    }

    vector<int> query(int idx, int low, int high, int l, int r, int seg1[][3]) {
        // no overlap
        if (r < low || l > high)
            return {0, 0, 0};

        // complete overlap
        if (l <= low && high <= r)
            return {seg1[idx][0], seg1[idx][1], seg1[idx][2]};

        int mid   = low + (high - low) / 2;
        vector<int> left  = query(idx * 2 + 1, low, mid, l, r, seg1);
        vector<int> right = query(idx * 2 + 2, mid + 1, high, l, r, seg1);
        return merge(left, right);
    }

    // void printSegmentTree() {
    //     for (int i = 0; i < 15; i++) {
    //         cout << i << ":  " << seg[i][0] << "  (:  " << seg[i][1] << "  ):  " << seg[i][2] << endl;
    //     }
    // }
// };

void solve() {
    // int t;
    // cin >> t;
    // while (t--) {
        string str;
        cin >> str;
        // cout << "str: " << str << endl;
        int n = str.size();
        int seg1[4 * n][3] = {0};
        // vector<vector<int>> seg1(4 * n, vector<int>(3));
        buildSegmentTree(0, 0, n-1, str, seg1);
        // seg1.printSegmentTree();
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            vector<int> ans = query(0, 0, n-1, l - 1, r - 1, seg1);
            cout << ans[0] << endl;
        }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);  // Faster I/O
    cin.tie(nullptr);  // Disable I/O synchronization
    solve();
}