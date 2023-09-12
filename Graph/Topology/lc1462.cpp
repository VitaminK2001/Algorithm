#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 通过拓扑排序判断是否为前驱，如果有直接相连关系或者间接相连（你的前驱是我的后继，那么我是你的前驱）

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int m = numCourses;
    vector<vector<bool>> isPre(m, vector<bool>(m, false));
    vector<int> indegree(m, 0); 
    vector<vector<int>> g(m); // graph
    for(auto p : prerequisites) {
        g[p[0]].push_back(p[1]);
        indegree[p[1]]++;
    }
    queue<int> q;
    for(int i = 0; i < m; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto nei : g[cur]) {
            isPre[cur][nei] = true;
            for(int i = 0; i < m; ++i) {
                isPre[i][nei] = isPre[i][cur] | isPre[i][nei];
            }
            indegree[nei]--;
            if(indegree[nei] == 0) {  // 在该点入度减少的时候判断是否入度为0
                q.push(nei);
            }
        }
    }
    vector<bool> res;
    for(auto p : queries) {
        res.push_back(isPre[p[0]][p[1]]);
    }
    return res;
}
