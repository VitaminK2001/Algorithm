#include <iostream>
using namespace std;
vector<int> g;
int main() {
    int n, N;
    cin >> n >> N;
    int a[n+1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long res = 0;
    for(int i = 0; i <= n; ++i) {
        if(i == n) res += (N-a[i]) * i;
        else res += (a[i+1]-a[i]) * i;
    }
}