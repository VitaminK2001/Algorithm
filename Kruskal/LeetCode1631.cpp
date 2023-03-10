#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        if(parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX != rootY) {
             if(rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            if(rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
        
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int> > edges;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int id = i * n + j;
                if(i > 0) {
                    int up = id - n;
                    int diff = abs(heights[i][j] - heights[i-1][j]);
                    edges.push_back({diff, id, up});
                }
                if(j > 0) {
                    int left = id - 1;
                    int diff = abs(heights[i][j] - heights[i][j-1]);
                    edges.push_back({diff, id, left});  // 匿名对象
                }
            }
        }
        sort(edges.begin(), edges.end());

        UnionFind uf(m * n);
        int res = 0;
        for(auto edge : edges) {
            int diff = edge[0];
            int u = edge[1];
            int v = edge[2];
            uf.Union(u, v);

            if(uf.Find(n*m-1) == uf.Find(0)) {res = diff; break;}
        }
        return res;
    }
};