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
    // 知道上限和下限天数的时候 可以用二分查找确定最优天数
    // 这里二分查找的逻辑是 l r 分别是下限和上限
    // 通过check函数确定r的位置 通过l+1判断是否超过r 超过说明r即为最小的天数
    int l = k, r = mx;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << r;
}