#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "TreeNode.cpp"

using namespace std;

class Solution_for_652_findDuplicateSubtrees{
public:
    unordered_map<string, int> memo;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return res;
    }
    string traversal(TreeNode* root) {
        if(root == nullptr) {
            return "#"; //结束符
        }
        string left = traversal(root->left);
        string right = traversal(root->right);
        string subTree = left + "," + right + "," + to_string(root->val);
        if(memo[subTree] == 1) {
            res.push_back(root);
        }
        memo[subTree]++;
        return subTree;
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        dfs(root, diameter);
        return diameter;
    }
    int dfs(TreeNode* root, int& diameter) {
        if(root == nullptr) return 0;

        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        int length = left + right;
        diameter = max(diameter, length);

        return 1 + max(left, right); // 包含根节点到左/右子节点的一段路径
    }
};