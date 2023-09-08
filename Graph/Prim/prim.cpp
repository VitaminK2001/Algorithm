#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3F3F3F3F;

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second - b.second;
    }
};

vector<pair<int, int> > adj[1000];
int dist[1000];
bool visited[1000];

void prim(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    pq.push(make_pair(start, 0));
    memset(dist, INF, sizeof(dist));
    memset(visited, false, sizeof(visited));
    dist[start] = 0;

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int u = cur.first;
        if(visited[u]) continue;
        visited[u] = true;
        for(pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if(!visited[v]) {
                dist[v] = weight;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // n为顶点数，m为边数
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); // 无向图
    }

    prim(0); // 从0号顶点开始生成最小生成树

    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        total_weight += dist[i];
    }
    cout << "Total weight of MST: " << total_weight << endl;

    return 0;
}