#include <iostream>
#include <vector>
using namespace std;

// 最多能放多少朵花
bool canPlaceFlowers(vector<int>& f, int n) {
    int m = f.size();
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        if((i == 0 || f[i-1] == 0) && f[i] == 0 && (i == m-1 || f[i+1] == 0)) {
            f[i] = 1;
            cnt++;
        }
    }
    return cnt >= n;
}
