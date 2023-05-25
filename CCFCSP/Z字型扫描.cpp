#include <iostream>
#define N 505
using namespace std;
int p[N][N];
int v[N][N];
int main() {
    int x = 1, y = 1, n, t = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> p[i][j];
        }
    }
    cout << p[1][1] << " ";
    v[1][1] = 1;
    while(t < n * n) {
        if(y + 1 <= n) {
            v[x][y+1] = 1;
            cout << p[x][y+1] << " ";
            y++;
            t++;
        }
        while(x+1 <= n && y-1 >= 1 && !v[x+1][y-1]) {
            v[x+1][y-1] = 1;
            cout << p[x+1][y-1] << " ";
            x++;
            y--;
            t++;
        }
        if(x + 1 <= n) {
            v[x+1][y] = 1;
            cout << p[x+1][y] << " ";
            x++;
            t++;
            
        }
        while(x-1 >= 1 && y+1 <= n && !v[x-1][y+1]) {
            v[x-1][y+1] = 1;
            cout << p[x-1][y+1] << " ";
            x--; 
            y++;
            t++;
        }
    }
    return 0;
}