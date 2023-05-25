/*无向连通图 通过树形结构 深度优先搜索 得到树的结点中 最远两点的距离 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// ansV表示距离最远的结点编号，ansLevel表示最远距离

vector<int> tree[20005];
int vis[20005];
int ansV = -1, ansLevel = 0;

void dfs(int v, int level) {
    vis[v] = 1;
    if(level > ansLevel) {
        ansLevel = level;
        ansV = v;
    }
    for(int i : tree[v]) {
        if(!vis[i]) {
            dfs(i, level+1);
        }
    }
}

int main() {
    int n, m, a;
    cin >> n >> m;
    // 一定要保证树上结点的编号是一致的
    for(int i = 2; i <= n+m; ++i) {
        cin >> a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    dfs(ansV, 0);
    cout << ansLevel;
    return 0;
}