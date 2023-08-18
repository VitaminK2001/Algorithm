#include <iostream>
#include <vector>
using namespace std;

/* 先序遍历求带权路径长度之和 */
typedef struct BiTNode {
    struct BiTNode *left, *right;
    int val;
    BiTNode(int v) {
        val = v;
    }
}BiTNode, *BiTree;

int preOrder(BiTree root, int deep) {
    static int wpl = 0;
    if(root->left == nullptr && root->right == nullptr) {
        wpl += deep*root->val;
    }
    if(root->left != nullptr) {
        preOrder(root->left, deep+1);
    }
    if(root->right != nullptr) {
        preOrder(root->right, deep+1);
    }
    return wpl;
}

int main() {
    BiTree root = new BiTNode(1);
    root->left = new BiTNode(2);
    root->right = new BiTNode(3);
    cout << preOrder(root, 0) << endl;
    delete root->left;
    delete root->right;
    delete root;
}