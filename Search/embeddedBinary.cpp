#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> a{1,2,3,3,3,3,3,4,5};
    // 找最后一个可以插入3的位置 不影响整体的顺序
    // 找大于目标数的位置
    auto it = upper_bound(a.begin(), a.end(), 3);
    cout << it-a.begin() << endl;

    // 找第一个可以插入3的位置 不影响整体的顺序
    // 找大于等于目标数的位置
    auto it2 = lower_bound(a.begin(), a.end(), 3);
    cout << it2-a.begin() << endl;
}