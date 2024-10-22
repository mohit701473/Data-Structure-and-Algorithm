
/*
 * Que. -> Why sorting is needed?
 * Sol. -> just consider only outer radius such that u have [7, 6, 3, 2]
 * now when u sort them then u have [2, 3, 6, 7] and after sorting when u
 * process them and suppose u are at idx = 1 i.e. at 3 (outer radius) then
 * u can say with 100% surity that if I am start from this outer radius then 
 * I don't need to look for the right side of the outer radius bcz they are
 * larger then it and u can't place them on top of it
 * 
 * Now think u did not done sorting then u have [7, 6, 3, 2] and when u are 
 * processing at idx = 2 i.e. outer radius = 3 then u can't say that right side
 * of outer radius are larger then it
 * 
 * This is the reason we need sorting.
 */

/*
 * Approch -> 1: Sort + Pick & Not Pick
 * MLE + TLE
 */
// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;


// ll solve(int idx, int lastIdx, vector<vector<int>> &arr, vector<vector<ll>> &dp) {
//     if (idx < 0)
//         return 0;

//     if (dp[idx][lastIdx + 1] != -1)
//         return dp[idx][lastIdx + 1];
    
//     ll pick = 0, notPick = 0;
//     int a = (lastIdx == -1) ? 0 : arr[lastIdx][1];

//     if (arr[idx][0] > a)
//         pick = solve(idx - 1, idx, arr, dp) + arr[idx][2];
    
//     notPick = solve(idx - 1, lastIdx, arr, dp);

//     return dp[idx][lastIdx + 1] = max(pick, notPick);
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<vector<int>> arr(n, vector<int> (3));
//     vector<vector<ll>> dp(n+1, vector<ll> (n+1, -1));
//     for (int i = 0; i < n; i++) {
//         int a, b, h;
//         cin >> a >> b >> h;
//         arr[i][0] = b;
//         arr[i][1] = a;
//         arr[i][2] = h;
//     }

//     sort(arr.begin(), arr.end());

//     cout << solve(n-1, -1, arr, dp);
// }



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<string, ll> mp;

ll solve(int idx, int lastIdx, vector<vector<int>> &arr) {
    if (idx < 0)
        return 0;

    string str = to_string(idx) + "#" + to_string(lastIdx);

    if (mp.find(str) != mp.end())
        return mp[str];
    
    ll pick = 0, notPick = 0;
    int a = (lastIdx == -1) ? 0 : arr[lastIdx][1];

    if (arr[idx][0] > a)
        pick = solve(idx - 1, idx, arr) + arr[idx][2];
    
    notPick = solve(idx - 1, lastIdx, arr);

    return mp[str] = max(pick, notPick);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (3));
    for (int i = 0; i < n; i++) {
        int a, b, h;
        cin >> a >> b >> h;
        arr[i][0] = b;
        arr[i][1] = a;
        arr[i][2] = h;
    }

    sort(arr.begin(), arr.end());
    
    cout << solve(n-1, -1, arr);
}