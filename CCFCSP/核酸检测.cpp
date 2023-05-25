#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int l, r;
    vector<int> v(200010);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        int tl = max(0, l - r - k + 1);
        int tr = max(0, l - k);
        for (int j = tl; j <= tr; j++)
            v[j]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> l;
        cout << v[l] << endl;
    }

    return 0;
}

// 采用差分数组
int m() {
    int n, m, k;
    cin >> n >> m >> k;
    int l, r;
    vector<int> v(200010);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        int tl = max(0, l - r - k + 1);
        int tr = max(0, l - k);
        v[tl]++;
        v[tr+1]--;
    }
    for(int i = 1; i < 200010; ++i) {
        v[i] += v[i-1];
    }
    for (int i = 0; i < m; i++) {
        cin >> l;
        cout << v[l] << endl;
    }

}