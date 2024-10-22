#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N (1 << 18)

class Info {
public:
    int cnt, i;
    char ch;

    Info() {
        this -> i = -1;
        this -> cnt = 1;
        this -> ch  = '#';
    }

    Info(int val, char ch, int i) {
        this -> cnt = val;
        this -> ch = ch;
        this -> i = i;
    }
};

string s;
int n;
Info seg[N];


Info merge(Info left, Info right, int i) {
    Info merged = Info();
    if (s[i] == '?') {
        merged.cnt = left.cnt + right.cnt;
        merged.ch = '?';
        merged.i = i;
    } else {
        merged.cnt = 1;
        merged.ch = s[i];
        merged.i = i;
    }

    cout << s[i];

    return merged;
}

void build(int idx, int low, int high, int level, int i) {
    if (low == high) {
        seg[idx] = Info();
        return;
    }

    int mid = low + (high - low) / 2;
    level += 1;
    build(idx * 2 + 1, low, mid, level, (n - (1 << level)));
    build(idx * 2 + 2, mid + 1, high, level, (n - (1 << level) + 1));
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2], i);
}

void update(int idx, int low, int high, int index, char ch) {
    if (low >= high)
        return;

    if (index == seg[idx].i) {
        seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2], index);
        return;
    }

    int left = seg[idx * 2 + 1].i;
    int right = seg[idx * 2 + 2].i;
    int mid = low + (high - low) / 2;
    if (index <= left) update(idx * 2 + 1, low, mid, index, ch);
    else update(idx * 2 + 2, mid + 1, high, index, ch);
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2], index);
}

int main() {
    int k;
    cin >> k;
    cin >> s;
    n = s.size() - 1;
    build(0, 0, (1 << k - 1), 0, n);
    cout << endl;
    cout << "enter q: \n";
    int q;
    cin >> q;
    while (q--) {
        int index;
        char ch;
        cin >> index >> ch;
        s[index-1] = ch;
        update(0, 0, (1 << k -1), index-1, ch);
        cout << seg[0].cnt << endl;
    }

}