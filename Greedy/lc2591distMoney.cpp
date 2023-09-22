#include <iostream>
using namespace std;

int distMoney(int money, int children) {
    money -= children;
    if(money < 0) return -1;
    if(money == 0) return 0;
    int cnt = min(money / 7, children); // 可能满7的人数小于children或者大于children
    money -= cnt * 7;
    children -= cnt;
    if((money == 3 && children == 1) || (money > 0 && children == 0)) {
        cnt--;
    }
    return cnt;
}