/* 
欧拉问题 需要满足两个条件才有解 
1. 给定图只有一个连通块
2. 不存在奇点（度为奇数的点）或者恰好存在两个而且起点是奇点

首先用并查集判断图是否连通，在图连通的基础下，判断奇点的数目
*/
#include <iostream>
using namespace std;
#define MAXN 400501
typedef struct {
    int e; // 边的终点
    int next; // next[i] = 与第i条边同起点的上一条边的存储位置
    int id;
}NODE;
NODE edge[MAXN];

typedef struct {
    int u, v, id; // 两端及编号
}EDGE;
EDGE Edge[MAXN];

int cnt;
int head[MAXN];

void add(int u, int v, int id) {
    edge[cnt].e = v;
    edge[cnt].next = head[u];
}