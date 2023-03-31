#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int tail[n];
        memset(tail, 0, sizeof(tail));
        // 每次找到当前数字应该插入的位置 这里找下界
        int res = 0;
        for(int num : nums) {
            int left = 0, right = res;
            while(left < right) {
                int mid = (left + right) >> 1;
                if(tail[mid] < num) {
                    left = mid+1;
                }else {
                    right = mid;
                }
            }
            tail[left] = num;
            if(res == right) res++;
        }
        return res;
    }
};



