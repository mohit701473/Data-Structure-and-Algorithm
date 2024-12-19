// // 3rd question
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int nums[]) {
    int ans = 0, flag = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] ^ flag == 0) {
            ans++;
            flag = !flag;
        }
    }

    return ans;
}


// int* solve(int n, vector<int> &nums) {
//     stack<int> st;

//     for (auto num: nums) {
//         if (!st.empty() && st.top() > num) {
//             int temp = st.top();
//             st.pop();
//             temp += nums;
//             st.push(temp);
//         } else st.push(num);
//     }
    
//     int sz = st.size();
//     int ans[sz];
//     for (int i = 0; i < sz; i++) {
//         ans[i] = st.top();
//         st.pop();
//     }



//     return ans;
// }

// int * solve(int n, int nums[]) {
//     stack<int> st;

//     for (int i = 0; i < n; i++) {
//         int curr = nums[i];
//         if (!st.empty() && st.top() > curr) {
//             curr += st.top();
//             st.pop();
//         }
//         st.push(curr);
//     }

//     int sz = st.size();
//     cout << "sz: " << sz << endl;
//     int* ans = new int[sz];

//     for (int i = sz-1; i >= 0; i--) {
//         ans[i] = st.top();
//         st.pop();
//     }

    

//     return ans;
// }

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // vector<int> nums(n);
    int nums[n];
    cout << "Enter values\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = solve(n, nums);

    // int sz = ans.length;
    
    // for (int i = 0; i < sz; i++)
    //     cout << ans[i] << " ";
    cout << "ans: " << ans << endl;
}


