#include <iostream>
#include <string>
#define N 100
using namespace std;
int nex[N];
string s, p;
int main() {
    cin >> s >> p;
    int n = s.size();
    int m = p.size();
    p.insert(p.begin(), ' ');
    s.insert(s.begin(), ' ');
    for(int i = 2, j = 0; i <= m; ++i) {
        while(j && p[i] != p[j+1]) j = nex[j];
        if(p[i] == p[j+1]) ++j;
        nex[i] = j;
    }
    for(int i = 1, j = 0; i <= n; ++i) {
        while(j && s[i] != p[j+1]) j = nex[j];
        if(s[i] == p[j+1]) ++j;
        if(j == m) cout << i-m << endl;
    }
    return 0;
}
