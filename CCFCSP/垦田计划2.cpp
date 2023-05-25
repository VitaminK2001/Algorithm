#include <iostream>
using namespace std;

const int N = 100010;
int c[N], t[N], mx; // 注意初始化数组的时候不能用变量 而应该用常量
int n, m, k;

// 采用贪心算法 每次总是找最大的去缩减
int find() {
    int mx = 0;
    for(int i = 1; i < n; ++i) {
        if(t[i] > t[mx]) {
            mx = i;
        }
    }
    return mx;
}

// 正确70% 剩下的运行超时
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
    }
    int flag = 0;
    while(m > 0) {
        int mx = find();
        if(c[mx] <= m) {
            m -= c[mx];
            t[mx] -= 1;
        }else {
            flag = 1;
            cout << t[mx];
            break;
        }
    }
    if(flag == 0) {
        int mx = find();
        cout << t[mx];
    }
}