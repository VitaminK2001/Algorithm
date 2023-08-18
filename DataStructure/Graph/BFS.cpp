#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 广度优先求解单源最短路长度问题
vector<pair<int, int>> g;
queue<int> q; bool visited[20]; int d[20];
void bfs_for_length(vector<pair<int,int>> &g, int u) {
    for(int i = 0; i < g.size(); ++i) {
        d[i] = INT_MAX;
    }
    visited[u] = true; d[u] = 0;
    q.push(u);
    while(!q.empty()) {
        int u = q.front(), v;
        q.pop();
        for(int i = 0; i < g.size(); ++i) {
            if(g[i].first == u){
                v = g[i].second;
                if(!visited[v]) {
                    visited[v] = true;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            } 
        }
    }
}


int main() {
    g.push_back(make_pair<int,int>(1,2));
    g.push_back(make_pair<int,int>(1,5));
    g.push_back(make_pair<int,int>(2,3));
    bfs_for_length(g, 1);
    cout << d[2] << endl;
    cout << d[3] << endl;
}