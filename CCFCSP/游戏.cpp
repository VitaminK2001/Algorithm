#include<iostream>
#include <queue>
using namespace std;

int dg[105][105][2];
int vis[105][105];

int addx[4] = {-1,1,0,0};
int addy[4] = {0,0,1,-1};

struct node {
    int x, y;
    node(){}
    node (int x, int y): x(x),y(y){}
};

bool checktime(int r, int c, int t) {
    return dg[r][c][0] <= t && t <= dg[r][c][1];
}

bool checkaround(int x, int y, int n, int m) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
    int n, m, t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> m >> t;
    }
    for(int i = 0; i < t; ++i) {
        int r,c,a,b;
        cin >> r >> c >> a >> b;
        dg[r][c][0] = a;
        dg[r][c][1] = b;
    }
    int tim = 0;
    deque<node> q;
    q.push_back(node(1,1));
    vis[1][1] = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            node cur = q.front();
            q.pop_front();
            for(int i = 0; i < 4; ++i) {
                int nx = cur.x + addx[i];
                int ny = cur.y + addy[i];
                if(nx == n && ny == m) {
                    cout << tim+1;
                    return 0;
                }
                // 这里不能用一次性的vis数组 阻断回头路的可能
                // 因为题目中存在危险方块，所以可能存在某一时间点 必须走回头路的情况
                // 通过记录每个坐标点在一个时间点是否入队 来判断是否可走
                // 而有些坐标点在一段连续的时间都是入队状态
                if(checkaround(nx, ny, n, m) && !checktime(nx, ny, tim+1) && !vis[nx][ny]) {
                    q.push_back(node(nx, ny));
                    vis[nx][ny] = 1;
                }
            }
        }
        tim++;
    }   
    return 0;
}

