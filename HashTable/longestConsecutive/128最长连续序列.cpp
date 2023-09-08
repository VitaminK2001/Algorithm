#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// https://leetcode.cn/problems/longest-consecutive-sequence/
/* 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &num : nums) {
            set.insert(num);
        }
        int longeststreak = 0;
        for(int num : nums) {
            if(!set.count(num-1)) { // 找起点
                int curnum = num;
                int curstreak = 1;
                while(set.count(curnum+1)) {
                    curnum += 1;
                    curstreak += 1;
                }
                longeststreak = max(longeststreak, curstreak);
            }
        }
        return longeststreak;
    }
};

