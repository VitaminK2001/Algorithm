#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
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

// 多叉树的定义
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
}; 