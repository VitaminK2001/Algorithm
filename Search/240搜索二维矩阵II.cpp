#include <iostream>
#include <vector>
using namespace std;

// 和I不同的点在于 是 mxn类型的矩阵
class Solution {
public:
    // 对每行进行二分查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto &row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if(it != row.end() && *it == target) return true;
        }
        return false;
    }
};