#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 双指针
    int threeSumClosest(vector<int>& nums, int target) {
        int gap = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for(int j = i+1, k = nums.size()-1; j < k; ) {
                int sum = num + nums[j] + nums[k];
                if(gap > abs(target-sum)){
                    gap = abs(target-sum);
                    ans = sum;
                } 
                if(sum < target) {
                    ++j;
                }else if(sum > target){
                    --k;
                }else {
                    return target;
                }
            }
        }
        return ans;
    }
};