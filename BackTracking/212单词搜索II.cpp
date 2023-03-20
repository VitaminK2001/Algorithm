#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 图的回溯
/*  暴力dfs加一个提前验证过程，直接可以时间击败98%。
    即：如果word里面含有boards中不存在的字符，或者某种字符的数量比boards中该字符数量更多，则根本不用进入dfs回溯，
    因为肯定无法形成该word。
    而且可以通过 题目中给出的信息 即字符串的长度小于10，所以当dfs到path长度大于10的时候 就应该返回
    m * n 个起点 每次往4个方向搜索 搜素的长度不超过10 所以时间复杂度 O(m * n * 4 ^ 10)
*/
class Solution {
public:
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> visit;
    unordered_set<string> set;
    vector<string> res;
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m, string& path) {
        if(path.size() > 10) return ;
        if(set.count(path)) {
            res.push_back(path);
            set.erase(path); // 为了防止下一次再搜索到该答案
        }
        for(const auto& dir : dirs) {
            int nx = i + dir[0];
            int ny = j + dir[1];
            if(visit[nx][ny]) continue;
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                path.push_back(board[nx][ny]);
                visit[nx][ny] = true;
                dfs(board, nx, ny, n, m, path);
                visit[nx][ny] = false;
                path.pop_back();
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        visit.assign(n, vector<bool>(m, false));
        for(int i = 0; i < words.size(); ++i) {
            set.insert(words[i]);
        }
        string path = "";
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                path.push_back(board[i][j]);
                visit[i][j] = true;
                dfs(board, i, j, n, m, path);
                visit[i][j] = false;
                path.pop_back();
            }
        }
        return res;
    }
};