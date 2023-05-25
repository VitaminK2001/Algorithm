#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 本题是求最长递增子序列
        // dp[i]表示以i结尾的最长递增子序列的长度
        int i, j, n = nums.size(), res = 0;
        vector<int> dp(n+1, 1);
        for(i = 0; i < n; ++i) {
            for(j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution2 {
    /*动态规划 + 二分查找*/
    // 如果找不到比当前tail末尾元素更小的元素就长度+1
public:
    int lengthOfLIS(vector<int>& nums) {
        // 二分查找找插入的位置
        // 找第一个大于等于num的位置插入
        // 若在当前区间范围内(0 ~ res) 找不到大于等于num的 则说明num是最大的，此时只能res++ 扩充容量
        int n = nums.size();
        int tail[n+1];
        int res = 0;
        for(int &num : nums) {
            int l = 0, r = res;
            while(l < r) {
                int m = (l + r) / 2;
                if(tail[m] < num) {
                    l = m+1;
                }else {
                    r = m;
                }
            }
            if(r == res) {
                res++;
            }
            tail[l] = num;
        }
        return res;
    }
};