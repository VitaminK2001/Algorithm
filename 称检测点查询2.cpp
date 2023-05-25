#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int d, i;
    // 对结构体进行自定义排序的第二种方法
    // 传入的是一个结构体类型node的常量引用，也就是一个不可修改的别名。
    // 这样可以避免拷贝结构体对象，提高效率，也可以保证传入的对象不被修改，增加安全性
    // operator函数后面有一个const，表示这个函数是一个常量成员函数，
    // 也就是说它不会修改当前对象的任何成员变量。这样可以保证重载运算符的纯粹性，也可以让这个函数适用于常量对象。
    bool operator<(const node& n) const {
        if(d == n.d) return i < n.i;
        else return d < n.d;
    }
}nodes[205];

// 下面说明 b 和 bs都是a的别名 bs表示一个长度为20的数组存储结构体a
// 也可以省略 a这个结构体原始的名字 写成 typedef struct {}b, bs[20];
typedef struct a {
    int x, y;
}b, bs[20];

// node nodes[205];


bool cmp(node n1, node n2) {
    if(n1.d == n2.d) return n1.i < n2.i;
    return n1.d < n2.d;
}

int main() {
    int n, x, y, nx, ny;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i) {
        cin >> nx >> ny;
        nodes[i].i = i;
        nodes[i].d = (nx - x) * (nx - x) + (ny - y) * (ny - y);
    }
    // 排序的时候从第二个开始排 一直排到第n+1个
    sort(nodes+1, nodes + n + 1, cmp);
    // 注意输出的时候 从第一个开始
    for(int i = 1; i <= 3; ++i) {
        cout << nodes[i].i << endl;
    }
}