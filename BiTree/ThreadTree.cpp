#include <iostream>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int ltag = 0;
    int rtag = 0;
    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    TreeNode(int val) {
        this->val = val;
        this->left == nullptr;
        this->right == nullptr;
    }
};

// 线索化
void Init(TreeNode *&node, TreeNode *&pre) { // 这里需要用引用改变指针本身
    if(node != nullptr) {
        Init(node->left, pre);
        if(node->left == nullptr) {
            node->ltag = 1;
            node->left = pre;
        }
        if(pre != nullptr && pre->right == nullptr) {
            pre->rtag = 1;
            pre->right = node;
        }
        pre = node;
        Init(node->right, pre);
    }
}

void createThread(TreeNode *root) {
    TreeNode *pre = nullptr;
    Init(root, pre);
    pre->right = nullptr;
    pre->rtag = 1;
}

// 找中序遍历的第一个节点
TreeNode *findFirst(TreeNode *node) {
    // 如果ltag = 0 说明该节点不是第一个节点
    while(node->ltag == 0) node = node->left;
    // 如果ltag = 1 说明该节点是第一个节点
    return node;
}

// 找中序遍历的最后一个节点
TreeNode *findLast(TreeNode *node) {
    // 如果rtag = 0说明当前节点不是最后一个节点
    while(node->rtag == 0) node = node->right;
    // 当rtag = 1的时候说明当前节点就是二叉树中序遍历的最后一个节点
    return node;
}

// 找当前节点的后继节点
TreeNode *findNext(TreeNode *node) {
    // 找右子树在二叉中序遍历中作为顶点的第一个节点
    if(node->rtag == 0) return findFirst(node->right);
    else return node->right;
}

// 找当前节点的前一个节点
TreeNode *findPrev(TreeNode *node) {
    // 找左子树在二叉中序遍历中作为顶点的最后一个节点
    if(node->ltag == 0) return findLast(node->left);
    else return node->left;
}

int main() {
    TreeNode* root = new TreeNode (1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    createThread(root);
    cout << findPrev(root)->val << endl;
    cout << findNext(root)->val << endl;
}