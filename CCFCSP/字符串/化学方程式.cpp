#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> plu;
// 首先根据等号、加号做拆分
int check_equal(string a) {
    for(int i = 0; i < a.length(); ++i) {
        if(a.at(i) == '=') return i;
    }
}
vector<int> check_plus(string a, int end) {
    for(int i = 0; i < end; ++i) {
        if(a.at(i) == '+') plu.push_back(i);
    }
}

int main() {

}