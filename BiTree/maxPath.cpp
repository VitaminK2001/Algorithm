#include "TreeNode.cpp"
#include <iostream>
#include <limits.h>

using namespace std;

int maxPathHelper(TreeNode* node, int& maxSum) {
    if(node == nullptr) return 0;
    int leftSum = maxPathHelper(node->left, maxSum);
    int rightSum = maxPathHelper(node->right, maxSum);

    int pathSum = node->val + max(leftSum, 0) + max(rightSum, 0);

    maxSum = max(maxSum, pathSum);

    // 为什么返回的时候没有考虑结点当做路径中间节点而是只当做起点或者起点和终点
    // 是因为上面的递归本来就只考虑了一边
    return node->val + max(0, max(leftSum, rightSum));
}

int maxPathSum(TreeNode *root) {
    int maxSum = INT_MIN;
    maxPathHelper(root, maxSum);
    return maxSum;
}

int main() {
    // 创建一棵二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    // 计算最大路径和
    int maxSum = maxPathSum(root);
    cout << "Max path sum: " << maxSum << endl; // 6
    
    // 释放内存
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}

