#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/* 如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。 */
// 该题能否用并查集的做法来解决 ?
class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        parent[fx] = fy;
    }
    bool check(vector<int>& now, int x) {
        for(int i = 0; i < now.size(); ++i) {
            if(now[i] == x) continue;
            if(find(now[i]) == find(x)) {
                return true;
            }
        }
        return false;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        parent.resize(n);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(abs(nums[i]-nums[j]) == k) {
                    Union(i, j);
                }
            }
        }
        int ans = 0;
        // 枚举子集所选的元素
        int choose[n];
        int cnt = 0;
        for(int mask = 1; mask < (1 << n); ++mask) {
            for(int i = 0; i < n; ++i) {
                if(mask & (1 << i)) {
                    choose[i] = 1;
                }else {
                    choose[i] = 0;
                }
            }
            vector<int> now;
            for(int i = 0; i < n; ++i) {
                if(choose[i] == 1 && !check(now, i)) {
                    now.push_back(i);
                }else {
                    cnt++; //说明这种状态 是 选择不了的
                    break;
                }
            }
        }
        ans = pow(2, n) - 1 - cnt; //总状态的数量 - 不能选择的状态的数量
        return ans;
    }
};