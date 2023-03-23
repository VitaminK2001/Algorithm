#include <iostream>
#include "TreeNode.cpp"
using namespace std;

/* 将原树中结点的值 变成原树中大于或等于node.val的值之和 */
class Solution {
public:
    int sum = 0;
    void dfs(TreeNode *root) {
        if(root == nullptr) {
            return ;
        }else {
            dfs(root->right);
            sum += root->val;
            root->val = sum;
            dfs(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};