#include <iostream>
#include <vector>
using namespace std;

// 同样是原数组是乱序的情况
// 构造一个数组tail，遍历tail数组，选择第一个大于等于nums[i]的位置插入
// 如果找不到 则tail 数组长度++ 将该元素添加到tail的末尾
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0, n = nums.size();
        int tail[n];
        memset(tail, 0, sizeof(tail));
        for(int num : nums) {
            int l = 0, r = res-1; // res表示长度
            while(l <= r) {
                int m = (l + r) >> 1;
                if(tail[m] >= num) {
                    r = m-1;
                }else {
                    l = m+1;
                }
            }
            if(l == res) {
                // 注意res-1是之前数组的最后一个位置
                tail[res] = num;
                res++;
            }else {
                tail[l] = num;
            }
        }
        return res;
    }
};
