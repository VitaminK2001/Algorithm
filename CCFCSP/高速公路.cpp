#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
 
//  有向图求强联通分量的算法
using namespace std;
 
const int maxn = 10010;
int cntn,cnte;
vector<int> G[maxn] , G2[maxn];
int vis[maxn];
vector<int> S;
int sccno[maxn],scc_cnt;
 
void getG2 () {
	for (int i = 1 ; i <= cntn ; i++) 
		for (int j = 0 ; j < G[i].size() ; j++) 
			G2[G[i][j]].push_back(i);
}
 
void dfs1 (int u) {
	if (vis[u]) return;
	vis[u]=1;
	for (int i = 0 ; i < G[u].size() ; i++)
		dfs1(G[u][i]);
	S.push_back(u);
}
 
void dfs2 (int u) {
	if (sccno[u]) return;
	sccno[u] = scc_cnt;
	for (int i = 0 ; i < G2[u].size() ; i++)
		dfs2(G2[u][i]);
}
 
void find_scc () {
	getG2();
	for (int i = 1 ; i <= cntn ; i++) if (!vis[i]) dfs1(i);
	for (int i = cntn-1 ; i >= 0 ; i--) {
		if (!sccno[S[i]]) {
			scc_cnt++;
			dfs2(S[i]);
		}
	}
}
 
int main() {
	int ans = 0;
	cin >> cntn >> cnte;
	
	for (int i = 0 ; i < cnte ; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	find_scc ();
	sort(sccno+1 , sccno+1+cntn);
	int cnt = 1;
	for (int i = 2 ; i <= cntn+1 ; i++) {
		if (sccno[i-1] == sccno[i])
			cnt++;
		else {
			ans += (cnt*(cnt-1))/2;
			cnt = 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}