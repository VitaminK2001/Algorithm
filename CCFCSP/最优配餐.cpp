#include <iostream>
#include <queue>
#define M 1000005
#define N 1005
using namespace std;

struct node {
    int x, y, dis;
    node();
    node (int tx, int ty, int z) {
        x = tx;
        y = ty;
        dis = z;
    }
};

int order[N][N] = {0}, vis[N][N] = {0};
int addx[4] = {-1, 1, 0, 0};
int addy[4] = {0, 0, 1, -1};
long long ans;

queue<node> q;

int n, m, k, d;

void bfs() {
    int xx, yy, i;
    while(!q.empty()) {
        node u = q.front();
        q.pop();
        for(i = 0; i < 4; ++i) {
            xx = u.x + addx[i], yy = u.y + addy[i];
            if(1 <= xx && xx <= n && 1 <= yy && yy <= n && !vis[xx][yy]) {
                /* !!!!!!如果这个地方没有订单则不会加到ans上!!!!!! */
                ans += (long long)order[xx][yy] * (u.dis + 1);
                vis[xx][yy] = 1;
                q.push(node(xx, yy, u.dis + 1));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m >> k >> d;
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        q.push(node(x, y, 0));
    }
    for(int i = 0; i < k; ++i) {
        cin >> x >> y >> z;
        order[x][y] += z;
    }
    for(int i = 0; i < d; ++i) {
        cin >> x >> y;
        vis[x][y] = 1;
    }
    bfs();
}