#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;
class Solution {
public:
    void dfs(TreeNode *node) {
        // 递归的翻转左右两颗子树
        if(node == nullptr || node->left == nullptr && node->right == nullptr) return ;
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        dfs(node->left);
        dfs(node->right);
    }


    TreeNode* invertTree(TreeNode* root) {
        // 迭代的遍历
        if(root == nullptr || root->left == nullptr && root->right == nullptr) return root;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
        return root;
    }
};