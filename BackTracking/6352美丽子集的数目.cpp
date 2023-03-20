#include <iostream>
#include <vector>
using namespace std;

/*  
    哈希表 + 回溯 
    哈希表的功能体现在 记录已经加入的nums[i]出现的次数 快速找到是否存在某个数
    回溯的功能是 选择nums[i]是否加入 如果nums[i]加入 则加入前后 对哈希表的影响是什么
    选择不加入 和 选择加入的顺序 可以颠倒
*/

// 该题能否用并查集来解决? 
class Solution {
public:
    int ans = 0;
    // 记录i出现的次数
    vector<int> visit;
    void dfs(vector<int>& nums, int pos, int k, int mx) {
        if(pos == nums.size()) {
            ans++;
            return ;
        }
        bool flag = true;
        if(nums[pos] + k <= mx && visit[nums[pos] + k]) flag = false;
        if(nums[pos] - k >=  0 && visit[nums[pos] - k]) flag = false;
        // 如果满足条件 则可以加入 也可以不加入
        
        // 不加入的入口
        dfs(nums, pos+1, k, mx);

        if(flag) { 
            visit[nums[pos]]++;
            // 加入的入口
            dfs(nums, pos+1, k, mx);
            // 加入的出口
            visit[nums[pos]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
        }
        visit.resize(mx+1, 0);
        dfs(nums, 0, k, mx);
        return ans-1; // 减掉全空的情况
    }
};