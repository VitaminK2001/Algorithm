#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    vector<int> id(plantTime.size());
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        return growTime[i] > growTime[j];
    });
    int ans = 0, days = 0;
    for(auto a : id) {
        days += plantTime[a];
        ans = max(ans, days + growTime[a]);
    }
    return ans;
}