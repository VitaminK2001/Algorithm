#include <iostream>
using namespace std;
const int N = 35, M = 3e5 + 10;

int book[N];
int dp[N][M];

int main() {
    int n, x, sum = 0;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> book[i];
        sum += book[i];
    }
    int res = 0;
    // i从1开始 i=0表示所有书都不选
    // 选哪几本书总额超过x ==> 不选哪几本书总额小于sum-x 小于的尽可能接近，大于的就尽可能小了
    for(int i = 1; i <= n; ++i) { // 从第一本书开始枚举选或者不选 状态由j的值决定
        for(int j = 0; j <= sum - x; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j >= book[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-book[i]]+book[i]);
            res = max(res, dp[i][j]);
        }
    }
    cout << sum - res;
}