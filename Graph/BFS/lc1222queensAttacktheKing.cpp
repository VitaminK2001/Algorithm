#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    // 从国王出发找8个方向上的王后，找到第一个就停止
    unordered_set<int> queens_pos(8*8);
    vector<vector<int>> res;
    for(auto p : queens) {
        queens_pos.insert(p[0]*8+p[1]); //采用一维方式记录坐标，简化之后的比较过程
    }
    int kx = king[0], ky = king[1];
    for(int dx = -1; dx <= 1; ++dx) {
        for(int dy = -1; dy <= 1; ++dy) {
            if(dx == 0 && dy == 0) continue;  
            int nx = kx + dx, ny = ky + dy;
            while((0 <= nx && nx < 8) && (0 <= ny && ny < 8)) {
                if(queens_pos.count(nx*8+ny)) {
                    res.push_back({nx, ny});
                    break;
                }
                nx += dx;
                ny += dy;
            }
        }
    }
    return res;
}

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    auto sgn = [](int x) -> int {
        return x > 0 ? 1 : (x == 0 ? 0 : -1);
    };
    // 从王后出发找国王，遍历所有的王后，距离最近的放入res
    vector<vector<int>> res;
    int kx = king[0], ky = king[1];
    int qx, qy, sx, sy, dx, dy, key;
    unordered_map<int, pair<vector<int>, int>> map; // 方向 -> (坐标，距离)
    for(auto &queen : queens) {
        qx = queen[0]; qy = queen[1];
        dx = abs(qx - kx); dy = abs(qy - ky);
        if(qx == kx || qy == ky || dx == dy) {
            sx = sgn(qx-kx); sy = sgn(qy-ky); // 注意这里是方向的正负号而不是qx qy的正负号
            key = sx * 10 + sy;
            if(!map.count(key) || map[key].second > dx+dy) {
                map[key] = make_pair(queen, dx+dy);
            }
        }
    }
    for(auto &[_, value] : map) {
        res.emplace_back(value.first);
    }
    return res;
}