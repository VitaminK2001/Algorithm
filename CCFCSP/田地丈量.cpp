#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x2 <= 0 || y2 <= 0) continue;
        if(x1 >= a || y1 >= b) continue;
        sum += (min(x2, a) - max(0, x1)) * (min(y2, b) - max(0, y1));
    }
    cout << sum << endl;
}