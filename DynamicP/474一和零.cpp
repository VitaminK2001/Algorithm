#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> get(2);
        for(int i = 0; i < str.length(); ++i) {
            get[str[i]-'0']++;
        }
        return get;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // 统计每个字符串1 和 0的数量
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(m+1, vector<int>(n+1)));
        
        for(int i = 1; i <= l; ++i) {
            vector<int> get = getZerosOnes(strs[i-1]);
            for(int k = 0; k <= m; ++k) {
                for(int j = 0; j <= n; ++j) {
                    dp[i][k][j] = dp[i-1][k][j];
                    if(k >= get[0] && j >= get[1]) {
                        dp[i][k][j] = max(dp[i][k][j], dp[i-1][k-get[0]][j-get[1]] + 1);
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};

