#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    // 对于每间房屋都有选择，偷或者不偷
    // 如果选择偷，则相邻两间（一间）房屋只能不偷
    // 如果选择不偷，则相邻房屋可以偷或者不偷

    // 考虑子问题的时候，考虑有几间房屋
    // 对于每个问题，将最后一间房屋考虑完后就是子问题
    int res = 0;
    vector<int> dp(nums.size());
    // size = 1
    if(nums.size() == 1) {
        return nums[0];
    }
    // 不考虑i+1
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    // size >= 3
    for(int i = 2; i < nums.size(); ++i) {
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[nums.size()-1];
}