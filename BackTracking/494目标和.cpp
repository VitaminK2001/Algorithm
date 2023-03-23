#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 这种做法过于暴力 
    int ans = 0;
    void dfs(vector<int>& nums, int pos, int n, int curSum, int target) {
        if(pos == n) {
            if(curSum == target){
                ans++;
            }
            return ;
        }
        // 如果前面添加正号
        dfs(nums, pos+1, n, curSum+nums[pos], target);

        // 如果前面添加负号
        dfs(nums, pos+1, n, curSum-nums[pos], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // 也是选择类的问题 选择对于当前的数 是前面填上正号还是负号
        int n = nums.size();
        dfs(nums, 0, n, 0, target);
        return ans;
    }
};