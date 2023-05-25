#include <cstdio>
#include <iostream>
#define N 20
using namespace std;

struct window {
    int x1, y1, x2, y2;
}w[N];

int deg[20] = {0};

bool check(int x, int l, int r) {
    return l <= x && x <= r;
}

void ask(int n, int tim, int x, int y) {
    int t = 0;
    for(int i = 1; i <= n; ++i) {
        if(check(x, w[i].x1, w[i].x2) && check(y, w[i].y1, w[i].y2) && deg[i] > deg[t]) {
            t = i;
        }
    }
    if(!t) cout << "IGNORED" << endl;
    else {
        deg[t] = tim;
        cout << t << endl;
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2;
        deg[i] = i;
    }
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        ask(n, n+i, x, y);
    }
    return 0;
}