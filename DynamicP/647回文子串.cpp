#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 */

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        // dp[i][j] 表示从i开始到j结束 的子串是否 回文串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) { // 每个位置自己都是一个单独的回文串
            dp[i][i] = true;
        }
        int ans = 0;
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
        // dp[i][j] = s[i] == s[j];
        for(int i = n-2; i >= 0; --i) {
            for(int j = i+1; j < n; ++j) {
                if(j - i < 3) {
                    dp[i][j] = s[i] == s[j];
                }else {
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }
};
