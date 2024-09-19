class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg = vector<int> (4 * n, 0);
        build(0, 0, n-1, nums, seg);
        // print();
    }

    void print() {
        for (auto &sum: seg)
            cout << sum << " ";
        cout << endl;
    }

    void build(int idx, int low, int high, vector<int> &arr, vector<int> &seg) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(idx * 2 + 1, low, mid, arr, seg);
        build(idx * 2 + 2, mid + 1, high, arr, seg);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }

    int query(int idx, int low, int high, int l, int r, vector<int> &seg) {
        // mo overlap
        if (r < low || l > high)
            return 0;

        // complete overlap
        if (l <= low && r >= high)
            return seg[idx];

        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(idx * 2 + 1, low, mid, l, r, seg);
        int right = query(idx * 2 + 2, mid + 1, high, l, r, seg);
        return left + right;
    }

    void updateSegmentTree(int idx, int low, int high, int i, int val, vector<int> &seg) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid)
            updateSegmentTree(idx * 2 + 1, low, mid, i, val, seg);
        else updateSegmentTree(idx * 2 + 2, mid + 1, high, i, val, seg);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }
    
    void update(int i, int val) {
        updateSegmentTree(0, 0, n-1, i, val, seg);
        // print();
    }
    
    int sumRange(int l, int r) {
        return query(0, 0, n-1, l, r, seg);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */