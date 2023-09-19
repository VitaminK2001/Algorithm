#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right) {}
};

/* 树形DP */
unordered_map<TreeNode*, int>  f, g;
void dfs(TreeNode* node) {
    if(!node) {
        return;
    }
    dfs(node->left);
    dfs(node->right);
    f[node] = g[node->left] + g[node->right] + node->val;
    g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
}

int rob(TreeNode* root) {
    dfs(root);
    return max(f[root], g[root]);
}