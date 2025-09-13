#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout<<"Enter size of coins array: ";
    cin >> n;
    vector<int> coins(n);
    cout<<"Coins Array: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout<<"Amount: ";
    cin >> amount;
    cout << "Output: "<<coinChange(coins, amount) << endl;
    return 0;
}
