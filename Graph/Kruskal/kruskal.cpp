#include <iostream>
#include <vector>
using namespace std;
// O(ElogE) 适合边稀疏图

class Edge{
public:
    int src, dest, weight;
};

class Graph{
public:
    int V, E; // 点的数量、边的数量
    vector<Edge> edges;
};

class Subset{
public:
    int parent;
    int rank;
};

int find(Subset subsets[], int i) {
    if(subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    }else if(subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void Kruskal(Graph graph) {
    int V = graph.V;
    vector<Edge> result(V-1);
    sort(graph.edges.begin(), graph.edges.end(), compare);

    Subset* subsets = new Subset[V];
    for(int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int e = 0, i = 0; 
    while(e < V-1 && i < graph.E) { // 遍历所有边，选出V-1条边，这v-1条边的两个顶点不能通过某条路径相连
        Edge next_edge = graph.edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if(x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Edges in MST:" << endl;
    for (int i = 0; i < V - 1; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}

int main() {
    Graph graph;
    graph.V = 4;
    graph.E = 5;
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({0, 3, 5});
    graph.edges.push_back({1, 3, 15});
    graph.edges.push_back({2, 3, 4});

    Kruskal(graph);

    return 0;
}

