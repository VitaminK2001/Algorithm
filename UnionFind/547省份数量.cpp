#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/number-of-provinces/
class Solution {
public:
    int Find(vector<int>& parent, int idx) {
        // 如果idx的爸爸不是原始爸爸
        if(parent[idx] != idx) {
            // 将idx的爸爸变成原始爸爸
            parent[idx] = Find(parent, parent[idx]);
        }
        return parent[idx];
    }
    void Union(vector<int>& parent, int id1, int id2) {
        parent[Find(parent, id1)] = Find(parent, id2);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(isConnected[i][j] == 1) {
                    Union(parent, i, j);
                }
            }
        }
        int province = 0;
        for(int i = 0; i < n; ++i) {
            if(parent[i] == i) {
                province++;
            }
        }
        return province;
    }
};