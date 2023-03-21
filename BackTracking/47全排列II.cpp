#include <iostream>
#include <vector>
using namespace std;

/* 包含可重复数字的数组, 按照任意顺序返回不重复的全排列 */
// 相同的数组不讨论
class Solution {
public:
    vector<bool> visit; // 表示一个树枝上的已经选中的数字 
    vector<vector<int>> res; 
    vector<int> path;
    vector<bool> used; // 表示同一层中相同的数字的第一个是否已经考虑完
    void dfs(vector<int>& nums, int depth, int n) {
        if(depth == n) {
            res.emplace_back(path);
            return ;
        }
        for(int i = 0; i < n; ++i) {
            if((i > 0 && nums[i] == nums[i-1] && !used[i-1]) || visit[i]) { //说明相同的数已经考虑完了 
                continue;
            }
            visit[i] = true; 
            used[i] = true; // 不同层的相同的数允许考虑
            path.push_back(nums[i]);
            dfs(nums, depth+1, n);
            path.pop_back();
            used[i] = false; // 相同层的相同的数不允许考虑
            visit[i] = false; 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        visit.resize(n, false);
        used.resize(n, false);
        dfs(nums, 0, n);
        return res;
    }
    
};