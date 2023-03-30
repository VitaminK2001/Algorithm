#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &num : nums) {
            set.insert(num);
        }
        int longeststreak = 0;
        for(int num : nums) {
            if(!set.count(num-1)) {
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

