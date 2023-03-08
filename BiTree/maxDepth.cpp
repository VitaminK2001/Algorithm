#include <iostream>
#include "TreeNode.cpp"

using namespace std;

int depth = 0;
int res = 0;

int traverse(TreeNode* root) {
    if(root == nullptr) return 0;
    depth++;
    if(root->left == nullptr && root->right == nullptr) {
        // 到达叶子结点后depth的值达到当前分支的最大值
        res = max(res, depth);
    }
    traverse(root->left);
    traverse(root->right);
    depth--;
    return res;
}

int maxDepth(TreeNode * root){
    if(root == nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    res = max(left, right) + 1;
    return res;
}

int main(){
    TreeNode* t = new TreeNode(1, nullptr, nullptr);
    t->left = new TreeNode(2, nullptr, nullptr);
    t->right = new TreeNode(3, nullptr, nullptr);
    t->right->right = new TreeNode(4, nullptr, nullptr);
    printf("%d", maxDepth(t));
}
