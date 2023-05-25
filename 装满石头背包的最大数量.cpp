#include <vector>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> a;
        for(int i = 0; i < capacity.size(); ++i) {
            a.push_back(rocks[i]-capacity[i]);
        }
        sort(a.begin(), a.end());
        int res = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] <= additionalRocks) {
                additionalRocks-=a[i];
                res++;
            }
        }
        return res;
    }
};