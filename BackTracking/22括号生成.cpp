#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 此题也是选择组合问题 选‘(‘  或者选‘)’ */
class Solution {
public:
    vector<string> res;
    bool isValid(string s) {
        int n = s.length();
        int balance = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') ++balance;
            else --balance;
            if(balance < 0) return false;
        }
        return balance == 0;
    }
    void dfs(string &path, int n, int pos) {
        if(pos == n && isValid(path)) {
            res.emplace_back(path);
            return ;
        }
        if(pos == n && !isValid(path)) return ;
        // 选择当前位置为'('
        path.push_back('(');
        dfs(path, n, pos+1);
        path.pop_back();

        // 选择当前位置为')'
        path.push_back(')');
        dfs(path, n, pos+1);
        path.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        dfs(path, 2*n, 0);
        return res;
    }

    // 可以在上面的基础上对dfs中的选择稍作修改
    // 在左括号的数量小于n的时候再放左括号
    // 在右括号数量小于左括号数量的时候再放右括号
    void dfs2(string& path, int n, int pos, int close, int open) {
        if(pos == n && isValid(path)) {
            res.emplace_back(path);
            return ;
        }
        if(pos == n && !isValid(path)) return ;
        if(open < n/2) {
            // 选择当前位置为'('
            path.push_back('(');
            open++;
            dfs2(path, n, pos+1, close, open);
            open--;
            path.pop_back();
        }
        if(close < open) {
            path.push_back(')');
            close++;
            dfs2(path, n, pos+1, close, open);
            close--;
            path.pop_back();
        }
    }
};