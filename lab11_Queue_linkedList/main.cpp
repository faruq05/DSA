#include <iostream>
#include <vector>
#include <climits>
#include "quetype.h"

using namespace std;

int main() {
    // Reading input values
    int n;
    cout << "Enter the number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the amount of money: ";
    cin >> amount;

    // Implementing the minimum coin change algorithm using dynamic programming
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Output the result
    if (dp[amount] == INT_MAX) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum number of coins required: " << dp[amount] << endl;
    }

    return 0;
}
