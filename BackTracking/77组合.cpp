#include <iostream>
#include <vector>
using namespace std;

// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    void dfs(int n, int pos, int k) {
        if(path.size() == k) {
            res.emplace_back(path);
            return ;
        }
        if(pos == n+1) return ;
        
        // 不选择当前的数
        dfs(n, pos+1, k);
        // 选择当前的数
        path.push_back(pos);
        dfs(n, pos+1, k);
        path.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, 0, k);
        return res;
    }
};

int main() {
    int n = 4, k = 2;
    Solution s;
    s.combine(n, k);
}