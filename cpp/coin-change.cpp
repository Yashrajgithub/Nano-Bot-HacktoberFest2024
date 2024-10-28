#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = coinChange(coins, amount);

    if (result != -1)
        cout << "Minimum coins required: " << result << endl;
    else
        cout << "Not possible to make the amount with the given coins." << endl;

    return 0;
}
