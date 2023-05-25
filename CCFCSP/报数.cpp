#include <iostream>
using namespace std;

bool check(int x) { 
    if(x % 7 == 0) return true;
    while(x > 0) {
        if(x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    int cnt = 0, t = 0;
    int res[4] = {0};
    for(int i = 1; cnt < n; ++i) {
        if(check(i)) res[t]++;
        else cnt++;
        t = (t + 1) % 4;
    }
    for(int i = 0; i < 4; ++i) {
        cout << res[i] << endl;
    }
}