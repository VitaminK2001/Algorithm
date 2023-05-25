#include <iostream>
#include <vector>

using namespace std;
struct Edge{
    int from;
    int to;
    int weight;
};

// bellmanford算法中允许 负边的存在 而且可以检查 是否存在负环
void bellman_ford(int start, vector<Edge>& edges, vector<int>& distance) {
    int n = distance.size();
    fill(distance.begin(), distance.end(), numeric_limits<int>::max());
    distance[start] = 0;
    for(int i = 0; i < n; ++i) {
        // 对于由n个结点的图 任意两点之间的距离最多是n-1条边
        // 如果两个点之间的路径 大于 n-1条边 
        // 则必存在环 可能是正环或者负环
        // 正环 正环上的任意两点之间的距离都小于整个环的距离
        // 负环 负环每经过一次循环 所得到的整个环的长度 都会变小 最后整个环的长度是 负无穷
        // 因为松弛 是按照边给出的顺序来的 一轮松弛至少可以确定一个最短路径上一个点到前一个点的距离 所以至多需要n-1轮可以确定完所有最短路径
        // 此时在多进行一轮 如果发现还有点可以松弛 则说明存在负环
        for(const auto& edge : edges) {
            if(distance[edge.from] != numeric_limits<int>::max() && distance[edge.to] > distance[edge.from] + edge.weight) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
        for(const auto& edge : edges) {
            if(distance[edge.from] != numeric_limits<int>::max()){
                distance[edge.to] > distance[edge.from] + edge.weight;
                cout << "negative circle detected" << endl;
                return;
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    vector<int> distances(n);
    bellman_ford(start, edges, distances);

    for (int i = 0; i < n; i++) {
        cout << distances[i] << " ";
    }
    cout << endl;

    return 0;
}