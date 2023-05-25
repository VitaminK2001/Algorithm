#include <iostream>
using namespace std;

const int N = 100010;
int c[N], t[N], mx; // 注意初始化数组的时候不能用变量 而应该用常量
int n, m, k;

bool check(int mid) {
    int res = 0;
    for(int i = 0; i < n; ++i) {
        if(t[i] > mid) {
            res += (t[i]-mid) * c[i];
        }
    }
    return res <= m;
}

/* 采用二分法解决搜索类的问题 正确100% */
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
        mx = max(mx, t[i]);
    }
    int l = k, r = mx;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << r;
}