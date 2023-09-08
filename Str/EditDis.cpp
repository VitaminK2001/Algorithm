#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/edit-distance/solutions/189676/edit-distance-by-ikaruga/

int minDistance(string s1, string s2) {
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i = 0; i <= s1.size(); ++i) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= s2.size(); ++j) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= s1.size(); ++i) {
        for(int j = 1; j <= s2.size(); ++j) {
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
    }
    return dp.back().back();
}