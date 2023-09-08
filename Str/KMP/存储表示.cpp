#include <iostream>
#include <string>
#define MAXLEN 255
using namespace std;
typedef struct {
    char ch[MAXLEN];
    int length;
}SString;

typedef struct {
    char *ch;
    int length;
}HString;

// https://www.cnblogs.com/labuladong/p/13933781.html

// KMP算法
int KMP(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    int dp[m][256], X = 0;
    dp[0][pat.at(0)] = 1;
    for(int i = 1; i < m; ++i) {
        for(int c = 0; c < 256; ++c) {
            dp[i][c] = dp[X][c];
        }
        dp[i][pat.at(i)] = i+1;
        X = dp[X][pat.at(i)];
    }
    int j = 0;
    for(int i = 0; i < n; ++i) {
        j = dp[j][pat.at(i)];
        if(j == m) return i-j+1;
    }
    return -1;
}