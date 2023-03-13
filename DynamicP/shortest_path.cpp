#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution_for_1091 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        // 存放已经遍历的点的坐标
        queue<pair<int, int>> q;
        // 存放方向
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        q.emplace(0,0);
        grid[0][0] = 1;
        int ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz != 0) {
                int x = q.front().first;
                int y = q.front().second;
                if(x == n-1 && y == m-1) return ans;
                q.pop();
                for(auto dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny]) continue;
                    // 因为这个emplace是放在后面所以算作下一轮
                    q.emplace(nx, ny);
                    // 这里的grid赋值不会影响本轮，因为没有在pop出来的时候做判断，而是只对nx ny做判断，所以同一轮pop出来的位置不会相互影响
                    grid[nx][ny] = 1;
                }
                sz--;
            }
            ans++;
        }
        return -1;
    }
};

// 另外一种思想和这种差不多，主要是在于用dp数组记录步数
// 这样就不用多写一个while循环
// 少一层while循环的原因是不需要通过里面while循环的次数来统计路径的长度
// 队列为空时（即图中所有点都进过队列或者为grid=1) 就已经完成任务
class Solution2_for_1091 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1]) return -1;
        // 记录到达每个格子所用的最短路径长度
        vector<vector<int> > dp(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int, int>> q;
        q.emplace(0,0);
        grid[0][0] = 1;
        dp[0][0] = 1;
        int ans = 1;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny]) continue;
                dp[nx][ny] = min(dp[nx][ny], dp[x][y] + 1);
                q.emplace(nx, ny);
                grid[nx][ny] = 1;
            }
        }
        return dp[n-1][m-1] == INT_MAX ? -1 : dp[n-1][m-1];
    }
};
