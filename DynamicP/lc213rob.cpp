#include <iostream>
#include <vector>
using namespace std;
const int N = 101;
int dp[N][2];
int rob(vector<int>& nums) {
    // 分别考虑偷第一间房屋和偷最后一间房屋
    int n = nums.size();
    if(n == 1) return nums[0];
    else if(n == 2) return max(nums[0], nums[1]);
    return max(solve(nums, 1, n-1), solve(nums, 0, n-2));
}

int solve(vector<int>& nums, int l, int r) {
    memset(dp, 0, sizeof(dp));
    dp[l][1] = nums[l];
    for(int i = l+1; i <= r; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[i];
    }
    return max(dp[r][0], dp[r][1]);
}
