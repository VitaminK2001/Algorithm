#include <vector>
using namespace std;
/* dp之方案总数 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if(sum + target < 0 || (sum + target)%2 != 0) return 0;
        int res = (sum + target) / 2;
        int n = nums.size();
        int dp[n+1][res+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            int num = nums[i-1];
            for(int j = 0; j <= res; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= num) dp[i][j] += dp[i-1][j-num];
            }
        }
        return dp[n][res];
    }
};

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if(sum + target < 0 || (sum + target)%2 != 0) return 0;
        int res = (sum + target) / 2;
        int n = nums.size();
        int dp[res+1];
        for(int i = 1; i <= n; ++i) {
            int num = nums[i-1];
            for(int j = res; j >= num; --j) {
                dp[j] += dp[j-num];
            }
        }
        return dp[res];
    }
};

/* 回溯的方法 */
class Solution3 {
public:
    int count = 0;
    void backtrack(vector<int>& nums, int target, int index, int sum) {
        if(index == nums.size()) {
            if(sum == target) count++;
        }else {
            // 将可能性作为递归的入口
            backtrack(nums, target, index+1, sum-nums[index]);
            backtrack(nums, target, index+1, sum+nums[index]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }
};