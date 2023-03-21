#include <iostream>
#include <vector>
using namespace std;

/* 不含重复数字的数组 给出全排列 只要数字出现的次数不同就算一个全排列*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int>& nums, int depth, int n) {
        if(depth == n) {
            res.emplace_back(path);
            return ;
        }
        // 只需要判断当前的数是否用过 每一层都从头开始枚举每个数 没用过就用 保证每个数在每一层都只被判断一次
        for(int i = 0; i < n; ++i) {
            if(!used[i]) {
                used[i] = true;
                path.emplace_back(nums[i]);
                dfs(nums, depth+1, n);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        used.assign(n, false);
        dfs(nums, 0, n);
        return res;
    }
};