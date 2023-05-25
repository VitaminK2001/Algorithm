#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef struct window{
    int x1, y1, x2, y2;
    int rank;
}window;

struct cmp {
    bool operator()(const window& a, const window& b) {
        return a.rank > b.rank;
    }
};

bool check(int x, int y, int x1, int y1, int x2, int y2) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int main() {
    /* N: 窗口个数 M: 点击次数*/
    int N, M;
    cin >> N >> M;
    list<window> w;
    int tim = 0;
    for(int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        w.push_front({x1, y1, x2, y2, tim++});
    }

    for(int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        int cnt = 1, flag = 0;
        for(auto it = w.begin(); it != w.end(); ++it, ++cnt) {
            if(check(x, y, (*it).x1, (*it).y1, (*it).x2, (*it).y2)) {
                flag = 1;
                w.push_front({(*it).x1, (*it).y1, (*it).x2, (*it).y2, tim++});
                w.erase(it);
                cout << cnt;
                break;
            }
        }
        if(flag == 0) cout << "IGNORED";
    }
}