#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        /*dp[i] 表示以nums[i]结尾的最长上升子序列的长度
        cnt[i] 表示以nums[i]结尾的最长上升子序列的个数 */
        // 最后统计最长的长度的个数
        int n = nums.size();
        int i, j;
        vector<int> dp(n+1, 1);
        vector<int> cnt(n+1, 1);
        int maxLen = 0, maxCnt = 0;
        for(i = 0; i < n; ++i) {
            for(j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            /*
                单纯计数是不行的，因为个数是在长度上有累加
                maxLen = max(maxLen, dp[i]);
                maxCnt = max(maxCnt, cnt[i]);
            */
            //  这是最长的长度
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                maxCnt = cnt[i];
            } else if(dp[i] == maxLen) {
                maxCnt += cnt[i];
            }
        }
        return maxCnt;
    }
};