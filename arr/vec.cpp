#include <iostream>
using namespace std;

int main() {
    vector<int> a(3, 5);
    for(int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
    vector<int>::iterator it = a.begin();
    a.erase(it+1, it+2); // 删除掉第二个元素
    cout << a.size() << endl;

    a.insert(it+2, 3, 5);
    cout << a.size() << endl;

}