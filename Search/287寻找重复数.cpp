#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 二分查找
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 要找的是出现次数 > 本身 的第一个的数 是lower bound
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l <= r) { 
            int mid = (l + r) >> 1;
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if(cnt <= mid) {
                l = mid+1;
            }else { // 在伸缩，将大于的数往前伸缩
                r = mid-1; 
                ans = mid; 
            }
        }
        return ans;
    }
};
