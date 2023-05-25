#include <iostream>
using namespace std;
// 和 I 不同之处在于 存在重复数

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[right]) {
                right = mid;
            }else if(nums[mid] > nums[right]) {
                left = mid+1;
            }else {
                right -= 1;
            }
        }
        return nums[left];
    }
};