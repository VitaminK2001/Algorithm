#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool run[2001];
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b){return a[1] < b[1];});
        int ans = 0;
        for(auto task : tasks) {
            int start = task[0], end = task[1], d = task[2];
            for(int i = start; i <= end; ++i) {
                d -= run[i];
            }
            for(int j = end; d > 0; --j) {
                if(!run[j]) {
                    run[j] = true;
                    d -= run[j];
                    ++ans;
                }
            }
        }
        return ans;
    }
};