#include <iostream>
#include <vector>
using namespace std;

bool checkValidGrid(vector<vector<int>>& grid) {
    if(grid[0][0] != 0) return false;
    int n = grid.size();
    vector<array<int, 2>> indices(n*n); // 如果不初始化直接存数会报错
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            indices[grid[i][j]] = {i, j}; //存储第gird[i][j]跳在哪个位置
        }
    }
    for(int i = 0; i < indices.size()-1; ++i) { //一共有n*n跳
        int dx = abs(indices[i+1][0] - indices[i][0]);
        int dy = abs(indices[i+1][1] - indices[i][1]);
        if(2 != dx * dy) return false;
    }
    return true;
}