#include <iostream>
#include <vector>
using namespace std;
int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int cnt = 0;
    vector<int> col;
    for(int i = 0; i < n; ++i) {
        col.clear();
        for(int j = 0; j < n; ++j) {
            col.emplace_back(grid[j][i]);
        }
        for(int k = 0; k < n; ++k) {
            if(col == grid[k]) cnt++;
        }
    }
    return cnt;
}