#include <iostream>
#include <vector>
using namespace std;
int a[500003] = {0};
int d[500003] = {0};
int main() {
    /*  
    p足够大，所有的数都被海水淹没了，只有0个岛屿:
    海平面逐渐下降，岛屿数量出现变化。每当一个凸峰出现，岛屿数就会多一个；
    每当一个凹谷出现，原本相邻的两个岛屿就被这个凹谷连在一起了，岛屿数减少一个。
    */
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int t = 1;
    // 将左右相等的数看做一个整体
    for(int i = 1; i <= n; ++i) {
        if(a[i] == a[i-1]) continue;
        a[t++] = a[i];
    }
    n = t-1;
    a[0] = a[n+1] = 0; //重新设置一头一尾的0
    for(int i = 1; i <= n; ++i) {
        // 题目中说小于p的数全部变成0
        // 如果p 从a[i]+1变成a[i]时 非零段会增加一个
        if((a[i] > a[i-1]) && (a[i] > a[i+1])) d[a[i]]++;
        // 如果p 从a[i]+1变成a[i]时 非零段会减少一个
        if((a[i] < a[i-1]) && (a[i] < a[i+1])) d[a[i]]--;
    }
    int sum = 0, ans = 0;
    for(int i = mx; i >= 0; --i) {
        sum += d[i];
        ans = max(ans, sum);
    }
    cout << ans;
}