#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 二分查找
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 要找的是第一个出现次数 > 本身 的数
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
                ans = mid; //之所以这里需要用ans记录 是因为[l,r]是闭区间
            }
        }
        return ans;
    }

    // 开区间的写法
    int findDuplicate(vector<int>& nums) {
        // 找出第一个 小于等于的数出现次数大于本身 的数
        int n = nums.size();
        int l = 1, r = n, mid = 0; 
        while(l < r) { // 如果最后l = r说明重复的数字就是r 因为题目保证一定有重复的数字
            mid = (l + r) / 2;
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                if(nums[i] <= mid) {
                    cnt++;
                }
            }
            if(cnt <= mid) {
                l = mid+1;
            }else {
                r = mid;
            }
        }
        return l;
    }   
};
