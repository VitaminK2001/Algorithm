#include <iostream>
#include <vector>
using namespace std;

/*  限定每个元素至多取一次，可能存在重复的元素
    返回所有元素和 = target的方案（不能重复）
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    void dfs(vector<int>& candidates, int n, int curPos, int curSum, int target) {
        if(curPos > n || curSum > target) { //注意这里不能设置成>= 不然数组的最后一个如果是target就不会加入到res中
            return ;
        }
        if(curSum == target) {
            res.emplace_back(path);
            return ;
        }
        // 可能存在[1,7,1] target = 8 就不能简单的for循环遍历了 因为[1,7] [7,1]是同一种方案
        // 将[1,7,1] 排序后[1,1,7] 这样并且不在后面的1延展
        for(int i = curPos; i < n; ++i) {
            // 只考虑相同元素的第一个元素
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue;
            // 不存在选或者不选，因为for循环帮我们遍历了所有的情况
            used[i] = true;
            path.emplace_back(candidates[i]);
            dfs(candidates, n, i+1, curSum+candidates[i], target);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        used.assign(n, false);
        dfs(candidates, n, 0, 0, target);
        return res;
    }   
};