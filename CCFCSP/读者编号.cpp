#include <iostream>
#define N 1005
using namespace std;
int cnt[N];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
        cout << cnt[a] << " ";
    }
}