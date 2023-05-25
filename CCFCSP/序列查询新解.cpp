#include <iostream>
#include <vector>
using namespace std;

long long m1(long long a[], int target, long long l, long long r) {
    // 找到第一个小于等于的位置
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m] <= target) {
            l = m+1;
        }else {
            r = m-1;
        }
    }
    return r;
}

int main() {
    long long n;
    long long N;
    cin >> n >> N;
    long long a[n+1];
    vector<long long>g(N+1);
    vector<long long>f(N+1);
    a[0] = 0, g[0] = 0, f[0] = 0;
    long long r = N / (n+1);
    for(long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long sum = 0;
    for(long long i = 1; i < N; ++i) {
        g[i] = i / r;
        f[i] = m1(a, i, 0, n);
        sum += abs(f[i] - g[i]);
    }
    cout << sum;
}

// 输入的数据
int n, N;
cin >> n >> N; // 用 cin 代替 input
vector<int> A(1, 0); // 用 vector 代替 list
for (int i = 0; i < n; i++) {
 int x;
 cin >> x;
 A.push_back(x); // 用 push_back 代替 extend
}
A.push_back(N);
int r = N / (n + 1);
vector<int> B;
for (int i = 0; i * r < N; i++) {
 B.push_back(i * r);
}
B.push_back(N);
set<int> s(A.begin(), A.end()); // 用 set 来去重和排序
s.insert(B.begin(), B.end()); // 用 insert 来合并两个序列
vector<int> v(s.begin(), s.end()); // 用 vector 来存储 set 的元素
int L = v.size();

// 离散化
vector<int> tree(L - 1, 0); // 初始化为全零
for (int i = 0; i < n + 1; i++) {
 int a = lower_bound(v.begin(), v.end(), A[i]) - v.begin(); // 用 lower_bound 来代替 bisect_left
 int b = lower_bound(v.begin(), v.end(), A[i + 1]) - v.begin();
 for (int j = a; j < b; j++) {
 tree[j] += i;
 }
}
for (int i = 0; i < B.size() - 1; i++) {
 int a = lower_bound(v.begin(), v.end(), B[i]) - v.begin();
 int b = lower_bound(v.begin(), v.end(), B[i + 1]) - v.begin();
 for (int j = a; j < b; j++) {
 tree[j] -= i;
 }
}

// tree 求两边的差值的划分
long long ans = 0; // 注意可能会溢出，所以用 long long 类型
for (int i = 0; i < L - 1; i++) {
 ans += abs(tree[i] * (v[i + 1] - v[i])); // abs 是求绝对值的函数
}
cout << ans << endl; // 输出结果
