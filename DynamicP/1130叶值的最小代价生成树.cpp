#include <iostream>
#include <vector>
using namespace std;

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    // dp[i][j] 表示子数组[i,j]的非叶子结点的和最小值
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX)), mval(n, vector<int>(n, 0));
    for(int j = 0; j < n; ++j) {
        dp[j][j] = 0;
        mval[j][j] = arr[j];
        for(int i = j-1; i >= 0; --i) {
            mval[i][j] = max(arr[i], mval[i+1][j]);
            for(int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + mval[i][k] * mval[k+1][j]);
            }
        }
    }
    return dp[0][n-1];
}