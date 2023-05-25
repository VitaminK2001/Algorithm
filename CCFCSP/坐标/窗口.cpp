#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
	int x1, y1, x2, y2, pri, id;
}window;

int t = 0;
int n, m;

bool cmp(const window& w1, const window& w2) {
	return w1.pri > w2.pri;
}

int check(int x, int y, window w[]) {
	sort(w, w + n, cmp);
	for(int i = 0; i < n; ++i) {
		if(w[i].x1 <= x && x <= w[i].x2 && w[i].y1 <= y && y <= w[i].y2) {
			w[i].pri = t++;
			// 这里不能return i+1 因为窗口按pri的大小重新排序了 这里的第 i+1 个不是最初的
			return w[i].id;
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	window w[n];
	for(int i = 0; i < n; ++i) {
		cin >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2;
		w[i].id = i+1;
		w[i].pri = t++;
	}

	int x, y;
	for(int i = 0; i < m; ++i) {	
		cin >> x >> y;
		int res = check(x,y,w);
		if(res == -1) cout << "IGNORED" << endl;
		else cout << res << endl;
	}
}



