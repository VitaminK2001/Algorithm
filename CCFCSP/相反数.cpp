#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0, j = N-1; i < j; ) {
        if(a[i] + a[j] == 0){
            ans++;
            ++i, --j;
        } 
        else if(abs(a[i]) > abs(a[j])) ++i;
        else if(abs(a[i]) < abs(a[j])) --j;
    }
    cout << ans;
}