#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        if(row == matrix.begin()) return false;
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 找最后一个不大于target的行首
        int low = -1, high = matrix.size()-1;
        while(low < high) {
            int mid = (high - low + 1) / 2 + low;
            if(matrix[mid][0] <= target) {
                low = mid;
            }else {
                high = mid-1;
            }
        }
        if(low == -1) return false;
        // 在low行中找target是否存在
        int left = 0, right = matrix[low].size()-1;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(matrix[low][mid] == target) return true;
            if(matrix[low][mid] < target) {
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        return false;
    }
};