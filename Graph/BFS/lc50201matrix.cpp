#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int, int>> q;
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(mat[i][j] == 0) {
                q.emplace(make_pair(i, j)) ;
                v[i][j] = 1;
            }
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int d = 0; d < 4; ++d) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && v[nx][ny] == 0) {
                v[nx][ny] = 1;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.emplace((nx, ny)); //可以直接这样用圆括号
            }
        }
    }
    return dist;
}