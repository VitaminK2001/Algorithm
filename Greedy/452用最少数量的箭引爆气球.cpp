#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int ans = 1;
        // for(int i = 0; i < points.size(); ++i) {
        //     int min = points[i][1];
        //     for(int j = i+1; j < points.size(); ++j) {
        //         if(min < points[j][0]) {
        //             i = j;
        //             ans++;
        //             break;
        //         }
        //     }
        // }
        int pos = points[0][1];
        for(const vector<int>& ballon : points) {
            if(pos < ballon[0]) {
                ++ans;
                pos = ballon[1];
            }
        }
        return ans;
    }

    
};

int main() {
    Solution solution;
    vector<vector<int>> points{{1,2},{3,4},{5,6},{7,8}};
    solution.findMinArrowShots(points);
}


