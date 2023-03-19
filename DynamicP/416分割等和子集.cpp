#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max = *max_element(nums.begin(), nums.end());
        if(n < 2 || (sum & 1)) return false;  /* 判断是否被2整除 */
        int target = sum / 2;
        if(max > target) return false; // 一定要判断，因为之后可能会出现数组越界的情况 因为初始化的大小是target

        // beigin
        /* dp[i][j] 表示从0~i中选取价值恰好为j的方案是否存在 */ 
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        for(int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= target; ++j) {
                if(j >= nums[i]) {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
        // end

        // 因为i之和i-1有关 所以从 begin 到 end 还可以用下面的代码
        vector<bool> dp2(target+1, false);
        dp2[0] = true;
        for(int i = 0; i < n; ++i) {
            for(int j = target; j >= 0; --j) {
                if(j >= nums[i]) {
                    dp2[j] = dp2[j] | dp2[j-nums[i]];
                }
            }
        }
        return dp2[target];
    }
};
