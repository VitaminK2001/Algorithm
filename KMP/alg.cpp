#include <iostream>
#include <string>
#define N 100
using namespace std;
int sensitive, T , nex[N];
string S, St;
// 在大小写敏感的情况下判断字符串中是否出现pattern
bool check(char s, char t) {
    if(!sensitive) {
        return tolower(s) == tolower(t);
    }
    return s == t;
}
int main() {
    cin >> S >> sensitive >> T;
    int n = S.size();
    for(int i = 1; i <= n-1; ++i) {
        int j = nex[i];
        while(j && check(S[i], S[j])) j = nex[j];
        nex[i+1] = check(S[j], S[i]) ? j+1 : 0;
    }
    while(T--) {
        cin >> St;
        int m = St.size();
        int j = 0;
        for(int i = 0; i <= m-1; ++i) {
            while(j && !check(St[i], S[j])) j = nex[j];
            if(check(St[i], S[j])) ++j;
            if(j == n) {
                cout << St << endl;
                break;
            }
        }
    }
}