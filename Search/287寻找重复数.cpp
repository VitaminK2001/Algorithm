#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 找小于等于 nums[i] 的个数 大于 nums[i]的第一个数
        int n = nums.size();
        int l = 1, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                // 因为数组本身不是有序的，所以只能构造 1 ~ n 的有序数组
                cnt += nums[i] <= mid;
            }
            if(cnt > mid) {
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
        return l;
    }
};