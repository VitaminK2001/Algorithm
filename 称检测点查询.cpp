#include <iostream>
#include <vector>
using namespace std;
vector<int> d(205, 0);
int main() {
    int n, x, y, d1 = INT_MAX, d2 = INT_MAX, d3 = INT_MAX;
    int a1 = 0, a2 = 0, a3 = 0;
    cin >> n >> x >> y;
    // 虽然下面的方法算出了 三个最小的序号 
    // 但是遇到重复的最小值的时候 并没有输出序号较小的那一个
    // 因为算法的逻辑是 d1 d2 d3 对应的序号是从小到大的
    for(int i = 1; i <= n; ++i) {
        int nx, ny;
        cin >> nx >> ny;
        d[i] = (nx - x) * (nx - x) + (ny - y) * (ny - y);
        if(d[i] < d1) {
            d1 = d[i];
            a1 = i;
        }else if(d1 <= d[i] && d[i] < d2){
            d2 = d[i];
            a2 = i;
        }else if(d2 <= d[i] && d[i] < d3) {
            d3 = d[i];
            a3 = i;
        }
    }
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
}
