#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool canPartition(vector<int>& nums) {
    int target = accumulate(nums.begin(), nums.end(), 0);
    if(target % 2 != 0) return false;
    int n = (int)nums.size(), m = target / 2;
    vector<vector<bool>> dp(n, vector<bool>(m+1, false)); //需要考虑的问题：目标值可能小于数组中的最大值，那算dp的时候下标可能超范围
    int maxNum = *max_element(nums.begin(), nums.end());
    if(maxNum > m) return false;
    for(int i = 0; i < n; ++i) {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(j >= nums[i]) {
                dp[i][j] = dp[i-1][j-nums[i]] | dp[i-1][j];
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n-1][m];
}