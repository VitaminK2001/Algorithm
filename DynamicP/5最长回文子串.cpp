#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 本题的关键只在于遍历 dp数组的顺序 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        int ans = 0;
        int start = 0;
        int end = 0;
        // 对于动态规划的子状态转移方程 
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
        // 可以看出在行遍历的顺序上，要先遍历出后面的 列则是要先遍历出前面的
        for(int i = n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(j - i < 3)  dp[i][j] = (s[i]==s[j]);
                else {
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                }
                if(dp[i][j] && ans < j-i+1){
                    ans = j-i+1;
                    start = i;
                    end = j;
                } 
            }
        }
        return s.substr(start, ans);
    }
};
