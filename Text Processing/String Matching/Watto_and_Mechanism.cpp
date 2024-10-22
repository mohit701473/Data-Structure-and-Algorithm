#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &temp, vector<int> &vec) {
    if (abs(temp[0] - vec[0]) == 1 && abs(temp[1] - vec[1]) == 0 && abs(temp[2] - vec[2]) == 0)
        return true;
    
    if (abs(temp[0] - vec[0]) == 0 && abs(temp[1] - vec[1]) == 1 && abs(temp[2] - vec[2]) == 0)
        return true;

    if (abs(temp[0] - vec[0]) == 0 && abs(temp[1] - vec[1]) == 0 && abs(temp[2] - vec[2]) == 1)
        return true;

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> inputs;
    vector<string> query;
    unordered_map<int, vector<vector<int>>> mp;

    while (n--) {
        string str;
        cin >> str;
        inputs.push_back(str);
    }

    while (m--) {
        string str;
        cin >> str;
        query.push_back(str);
    }

    for (auto &str: inputs) {
        vector<int> temp(3, 0);
        for (auto &ch: str)
            temp[ch - 'a']++;
        mp[str.size()].push_back(temp);
    }

    for (auto &str: query) {
        bool flag = false;
        vector<int> temp(3, 0);
        for (auto &ch: str)
            temp[ch - 'a']++;

        for (auto &vec: mp[str.size()]) {
            if (check(temp, vec)) {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }


}

int main() {
    // ios_base::sync_with_stdio(false);  // Faster I/O
    // cin.tie(nullptr);  // Disable I/O synchronization
    solve();
    return 0;
}