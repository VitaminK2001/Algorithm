#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 验证栈序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        stack<int> st;
        for(; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while(!st.empty() && popped[j] == st.top()) {
                st.pop();
                ++j;
            }
        }
        return j == pushed.size();
    }
};

// 原地模拟空间复杂度为O(1)
class Solutioin2 {
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        auto i = pushed.begin(), j = popped.begin();
        for(auto &v : pushed) {
            *i = v;
            while(i >= pushed.begin() && *i == *j) {
                --i;
                ++j;
            }
            ++i;
        }
        return i == pushed.begin();
    }
};