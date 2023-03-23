#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // 栈中存储的永远都是 最右边的(因为是从左到右遍历)没有被匹配的右括号的下标
        // 以及左括号的下标
        // 当栈中元素只有一个的时候 表示存储的是最右边的没有被匹配的右括号的下标
        // 当栈中的元素有多个的时候 从第二个开始一直到栈顶 都是待匹配的左括号的下标
        // 因为无论是左括号还是右括号 都会进栈
        // 所以栈顶元素永远是当前遍历的元素的前一个元素的下标
        // 只是右括号进栈的唯一情况就是 栈pop之后为空 表示之前栈里存放的也只是一个右括号的下标
        // 为了区分第一个左括号 和 最后一个右括号 匹配的时 栈pop之后为空的情况
        // 先将栈push -1 表示左括号前面一个元素的下标是-1
        // 所以如果一开始是右括号 栈pop之后为空 也不受影响
        stack<int> st;
        int maxans = 0;
        st.push(-1);
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                st.push(i);
            }else {
                st.pop(); // 栈为空的时候不会执行这个操作的
                if(st.empty()) {
                    st.push(i);
                }else {
                    maxans = max(maxans, i - st.top());
                }
            }
        }
        return maxans;
    }
};