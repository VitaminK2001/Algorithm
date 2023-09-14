#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge{ // 另一端点被 this 隐含
    int v;
    int weight;
};
typedef vector<vector<Edge> > Graph; // 每个点都有一个边所构成的集合

// 存储不同节点距离源点的距离
typedef pair<int, int> Node;

vector<int> dijkstra(const Graph& graph, int source) {
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    vector<bool> visit(n, false);

    // 优先队列存储的是节点，和源点距离近的结点靠队头
    // greater less 默认是第一个比较大小排序，greater是升序
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

        // 每次确定一个点的所有边所连的点距离原点的距离 （因为都是正边，三角形的两边之和大于第三边 所以一轮即可确定）
        for(const Edge& edge : graph[u]) {
            int v = edge.v;
            int weight = edge.weight;

            // 源点到u的距离 + u到v的距离 < 源点到v的距离
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
