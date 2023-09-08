#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *node, int prevSum) {
        if(node == nullptr) return 0; // 注意这里不是return prevSum
        int curSum = prevSum * 10 + node->val;
        if(node->left == nullptr && node->right == nullptr) {
            return curSum;
        }else {
            return dfs(node->left, curSum) + dfs(node->right, curSum);
        }
    }
    int sumNumbers(TreeNode* root) {
        int res = dfs(root, 0);
        return res;
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans;
        queue<TreeNode*> q;
        queue<int> s;
        q.push(root);
        s.push(root->val);
        while(!q.empty()) {
            TreeNode *curNode = q.front();
            q.pop();
            int curSum = s.front();
            s.pop();
            if(curNode->left == nullptr && curNode->right == nullptr) {
                // 叶子结点
                ans += curSum;
            }else {
                // 非叶子节点
                if(curNode->left != nullptr) {
                    q.push(curNode->left);
                    s.push(curSum * 10 + curNode->left->val);
                }
                if(curNode->right != nullptr) {
                    q.push(curNode->right);
                    s.push(curSum * 10 + curNode->right->val);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    s.sumNumbers(root);
}