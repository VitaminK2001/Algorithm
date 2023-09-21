#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    vector<vector<int>> g(n);
    vector<int> degree(n);
    for(auto x : edges) {
        g[x[0]].push_back(x[1]);
        g[x[1]].push_back(x[0]);
        ++degree[x[0]];
        ++degree[x[1]];
    }
    int rest = n;
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(degree[i]==1 && !coins[i]) {
            q.push(i);
        }
    }
    int cur;
    while(!q.empty()) {
        cur = q.front();
        --degree[cur];
        q.pop();
        --rest;
        for(auto nei : g[cur]) {
            --degree[nei];
            if(degree[nei]==1 && !coins[nei]) {
                q.push(nei);
            }
        }
    }
    // 删除树中所有叶子结点 2次
    for(int _ = 0; _ < 2; ++_) {
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        int cur;
        while(!q.empty()) { 
            cur = q.front();
            --degree[cur];
            q.pop();
            --rest;
            for(auto nei : g[cur]) {
                --degree[nei];
            }
        }
    }
    return rest == 0 ? 0 : 2*(rest-1);
}
