#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[left] < nums[mid]) {
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid-1;
                }else {
                    left = mid+1;
                }
            }
            if(nums[mid] > target) {
                left = mid+1;
            }else {
                right = mid;
            }
        }
        return nums[left] == target;
    }
};