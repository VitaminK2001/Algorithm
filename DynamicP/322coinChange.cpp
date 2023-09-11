#include <iostream>
using namespace std;
// 一个整数数组表示不同面额的硬币，一个整数amount表示总金额
// 计算返回凑成总金额需要的最少硬币的数量，认为每种硬币是无限的

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1); //硬币最小的面额是1
    dp[0] = 0;
    for(int i = 1; i <= amount; ++i) {
        for(int j = 0; j < coins.size(); ++j) {
            if(i >= coins[j]) dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
        }
    }
    return dp[amount] == amount+1 ? -1 : dp[amount];
}