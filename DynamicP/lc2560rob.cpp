#include <iostream>
#include <vector>
using namespace std;
/* 题目要求 在至少偷k间房屋的前提下，最小化所偷房屋的最大值(所偷的房屋仍然不能相邻)*/
int minCapability(vector<int>& nums, int k) {
    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    while(low <= high) {
        int mid = (low + high) >> 1;
        int count = 0;
        bool visited = false;
        for(int x : nums) {
            if(x <= mid && !visited) {
                count++;
                visited = true;
            }else { // 控制相邻房间不被选取的方式（flag turn）
                visited = false;
            }
        }
        if(count >= k) {
            high = mid - 1;
        }else { // 保证low指向的是>=k的第一个可能：让high指向>=k的前一个可能，如果low高于high表示low就是>=k的第一个可能
            low = mid + 1;
        }
    }
    return low;
}