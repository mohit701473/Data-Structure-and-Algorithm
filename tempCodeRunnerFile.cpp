#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of coins required
int minimumCoins(int amount, int n, int arr[]) {
    // Sort the coin denominations in descending order
    sort(arr, arr + n, greater<int>());
    
    int coinCount = 0; // To count the minimum coins required
    
    for (int i = 0; i < n; i++) {
        // Use as many coins of the current denomination as possible
        if (amount >= arr[i]) {
            coinCount += amount / arr[i]; // Add the number of coins used
            amount %= arr[i]; // Reduce the amount by the coins' total value
        }
        
        // If amount becomes zero, we found the answer
        if (amount == 0) break;
    }
    
    return coinCount;
}

int minCoinsUtil(int coins[], int m, int sum, int* dp)
{
    if (sum == 0)
        return 0;

    if (dp[sum] != -1)
        return dp[sum];

    int res = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (coins[i] <= sum) {
            int sub_res = minCoinsUtil(coins, m, sum - coins[i], dp);
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }

    dp[sum] = res;

    return res;
}


int minCoins(int coins[], int m, int sum)
{
    int* dp = new int[sum + 1];
    memset(dp, -1, sizeof(int) * (sum + 1)); // Initialize DP table with -1

    return minCoinsUtil(coins, m, sum, dp);
}

int main() {
    int amount, n;
    
    // Input the amount
    cout << "Enter the amount: ";
    cin >> amount;
    
    // Input the number of coin types
    cout << "Enter the number of different coins: ";
    cin >> n;
    
    int arr[n];
    
    // Input the coin denominations
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the function and display the result
    // int result = minimumCoins(amount, n, arr);
    int result = minCoins(arr, n, amount);
    cout << "Minimum number of coins required: " << result << endl;

    return 0;
}



// int minCoinsUtil(int coins[], int m, int sum, int* dp)
// {
//     if (sum == 0)
//         return 0;

//     if (dp[sum] != -1)
//         return dp[sum];

//     int res = INT_MAX;
//     for (int i = 0; i < m; i++) {
//         if (coins[i] <= sum) {
//             int sub_res = minCoinsUtil(coins, m, sum - coins[i], dp);
//             if (sub_res != INT_MAX && sub_res + 1 < res)
//                 res = sub_res + 1;
//         }
//     }

//     dp[sum] = res;

//     return res;
// }


// int minCoins(int coins[], int m, int sum)
// {
//     int* dp = new int[sum + 1];
//     memset(dp, -1, sizeof(int) * (sum + 1)); // Initialize DP table with -1

//     return minCoinsUtil(coins, m, sum, dp);
// }