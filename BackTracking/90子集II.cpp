#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// 数组的回溯

/*  该题在子集I 的基础上新增了可能包含重复的元素
    相较于子集I 的位运算的做法 通过0 1 标记选择
    子集II需要另一种解法 因为可能存在相同值的元素 在不同的选择情况中被选中
    最终的子集相同的结果
*/

/*
    就算用unordered_set容器装vector<int>容器
    也可能出现问题，因为vector<int>容器是不计算顺序的，哪怕出现的元素都相同 但是排列的顺序不同
    也被unordered_set认为是不同的vector<int>
*/
struct VectorHash {
    size_t operator()(const std::vector<int>& vec) const {
        size_t hash = 0;
        for (int i : vec) {
            hash ^= std::hash<int>()(i);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> ans;
        vector<vector<int>> res;
        int n = nums.size();
        
        for(int mask = 0; mask < (1<<n); ++mask) {
            vector<int> path;
            for(int i = 0; i < n; ++i) {
                if(mask & (1<<i)) {
                    path.push_back(nums[i]);
                }
            }
            ans.insert(path);
        }
        for(const auto& vec : ans) {
            res.insert(res.end(), vec);
        }
        return res;
    }
};

/*
上面的报错
输入 [4,4,4,1,4]
输出 
[[4,4,1,4],[1,4],[4,4,4,1],[4,1],[4,4,4,1,4],[4,1,4],[4,4,1],[1],[4,4,4],[4],[4,4,4,4],[4,4],[]]
期望输出
[[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
*/

class Solution2 {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int>& nums, int pos, int n) {
        // 每次延展树枝 都需要保存当前的子集
        res.push_back(path);
        for(int i = pos; i < n; ++i) { // 之所以用for循环是因为 每次进入递归函数的时候都是从当前的位置往后看，看的是待选的元素
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                continue;
            }
            // 遍历之前打开开关 让同一条树枝上的相同元素可以选入
            used[i] = true;
            path.push_back(nums[i]); //进入下一层的状态
            dfs(nums, i+1, n); // 只要进入到下一层 之前的数都不能用
            path.pop_back(); //回到当前层的状态
            // 遍历之后关闭开关 表示相同元素的第一个已经用完了 同一树层的相同元素没有必要再延展成树枝
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        used.assign(n, false);
        dfs(nums, 0, n);
        return res;
    }
};

// 写成没有for循环版本的可以吗？
class Solution3 {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int>& nums, int pos, int n) {
        if(pos >= n) return ;
        // 如果不选，则pos+?
        int i = pos;
        while(i > 0 && nums[i] == nums[i-1] && used[i-1] == true){
            i++;
        }
        dfs(nums, i, n);

        // 如果选择，进入下一层前，为了防止后面的数和之前的数相同
        // 需要做个标记，表示允许可以选
        used[pos] = true;
        path.emplace_back(nums[pos]);
        dfs(nums, pos+1, n);
        path.pop_back();
        used[pos] = false;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        used.assign(n, false);
        dfs(nums, 0, n);
        return res;
    }
};

