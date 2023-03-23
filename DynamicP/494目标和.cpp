#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if(abs(sum) < abs(target)) return 0;
        int t = 2 * sum + 1;
        int dp[n][t]; // -sum ~ sum 中间还有一个0
        memset(dp, 0, sizeof(dp));

        // dp[i][j]表示用 0~i 凑出来j有几种方案
        // dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
        // dp[0][-nums[0]] = dp[0][nums[0]] = 1;
        // 但是数组的下标是从0开始，所以整体移动sum个位置
        dp[0][sum-nums[0]] += 1;
        dp[0][sum+nums[0]] += 1;

        for(int i = 1; i < n; ++i) {
            for(int j = -sum; j <= sum; ++j) {
                if(j + nums[i] > sum) { // 因为之前的情况不能超出边界 所以只能从i-1的基础+nums[i]得到i的情况
                    dp[i][j+sum] = dp[i-1][j+sum-nums[i]];
                }
                else if(j - nums[i] < -sum) { // 同上
                    dp[i][j+sum] = dp[i-1][j+sum+nums[i]];
                }else { // 如果没有超出边界 则两种情况都有可能
                    dp[i][j+sum] = dp[i-1][j+sum+nums[i]] + dp[i-1][j+sum-nums[i]];
                }
            }
        }
        return dp[n-1][target+sum];
    }
};