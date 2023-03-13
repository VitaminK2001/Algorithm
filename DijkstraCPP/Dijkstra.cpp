#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
    int v;
    int weight;
};
typedef vector<vector<Edge> > Graph;

typedef pair<int, int> Node;

vector<int> dijkstra(const Graph& graph, int source) {
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    vector<bool> visit(n, false);

    priority_queue<Node, vector<Node>, greater<Node> > pq;

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int u = node.second;

        if(visit[u]){
            continue;
        }
        visit[u] = true;

        for(const Edge& edge : graph[u]) {
            int v = edge.v;
            int weight = edge.weight;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main(){
    int n = 6;
    int source = 0;

    Graph graph(n);

    // 添加边
    graph[0].push_back({1, 5});
    graph[0].push_back({2, 1});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 3});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 7});
    graph[2].push_back({4, 4});
    graph[3].push_back({4, 2});
    graph[3].push_back({5, 1});
    graph[4].push_back({5, 2});

    // 调用 Dijkstra 算法求最短路径
    vector<int> dist = dijkstra(graph, source);

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}
