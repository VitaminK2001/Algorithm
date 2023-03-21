#include <iostream>
#include <vector>
using namespace std;

/*  可以无限制的从一个每个元素都不重复的数组中选取元素 (即一个元素可以重复取)
    返回所有选取元素总和 = 目标值的方案（不能重复）
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& candidates, int curPos, int curSum, int target) {
        if(curPos >= candidates.size() || curSum > target) {
            return ;
        }
        if(curSum == target) {
            res.emplace_back(path);
            return ; //注意这个时候也需要 return 不然会继续往下递归
        }
        // 有选或者不选两种情况
        // 如果不选则直接curPos = i+1
        dfs(candidates, curPos+1, curSum, target);

        // 如果选则还是curPos = i
        path.push_back(candidates[curPos]);
        dfs(candidates, curPos, curSum+candidates[curPos], target);
        path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, 0, target);
        return res;
    }
};

// for循环的写法
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& candidates, int n, int curPos, int curSum, int target) {
        if(curPos >= n || curSum > target) {
            return ;
        }
        if(curSum == target) {
            res.emplace_back(path);
            return ;
        }
        for(int i = curPos; i < n; ++i) {
            // 不存在选或者不选，因为for循环帮我们遍历了所有的情况
            path.emplace_back(candidates[i]);
            dfs(candidates, n, i, curSum+candidates[i], target); //注意这里是i 因为一个元素可以重复用
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        dfs(candidates, candidates.size(), 0, 0, target);
        return res;
    }   
};