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
    // i从1开始 0表示所有书都不选
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= sum - x; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j >= book[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-book[i]]+book[i]);
            res = max(res, dp[i][j]);
        }
    }
    cout << sum - res;
}