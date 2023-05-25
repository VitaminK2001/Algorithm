#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 这种二分查找 的 left 虽然不等于 right 但是right起到的作用是设定位置 即可能结果的位置 
        // 当left 增长到 right的时候 说明right就是结果
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[right]) {
                right = mid;
            }else {
                left = mid+1;
            }
        }
        return nums[left];
    }
};