#include<iostream>
#include <vector>
using namespace std;
// 找大于等于这个数的第一个位置和大于等于这个数的最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // lower_bound找的是第一个大于等于该数的位置
        // upper_bound找的是第一个大于该数的位置
        vector<int> ans;
        auto first = lower_bound(nums.begin(), nums.end(), target);
        if(first == nums.end() || *first != target) return vector<int>{-1,-1};
        else ans.push_back(first-nums.begin());
        auto second = upper_bound(nums.begin(), nums.end(), target);
        if(*(second-1) == target) {
            ans.push_back(second-nums.begin()-1);
        }else {
            return vector<int>{-1,-1};
        }
        return ans;
    }
};

class Solution2 {
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        // 手动实现lowerbound和upperbound
        int l = 0, r = nums.size(), mid = 0;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid+1;
            }else {
                r = mid; 
            }
        }
        // l就是第一个大于等于的位置
        if(l == nums.size() || nums[l] != target) return vector<int>{-1,-1};
        else ans.push_back(l);

        
        l = 0, r = nums.size(), mid = 0;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] <= target) {
                l = mid+1;
            }else {
                r = mid;
            }
        }
        // l就是第一个大于的位置
        if(nums[l-1] == target){
            ans.push_back(l-1);
        }else {
            return vector<int>{-1,-1};
        } 
        return ans;
    }
};