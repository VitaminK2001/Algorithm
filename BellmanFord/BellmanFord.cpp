#include <iostream>
#include <vector>

using namespace std;
struct Edge{
    int from;
    int to;
    int weight;
};

void bellman_ford(int start, vector<Edge>& edges, vector<int>& distance) {
    int n = distance.size();
    fill(distance.begin(), distance.end(), numeric_limits<int>::max());
    distance[start] = 0;
    for(int i = 0; i < n; ++i) {
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