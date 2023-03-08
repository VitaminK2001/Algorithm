#include <iostream>
#include <stack>
#include "TreeNode.cpp"
typedef TreeNode node;
using namespace std;

class BinaryTreeTraversal{
public:
    void preOrderTraversal(node* root) {
        if(root == nullptr) return ;
        stack<node*> s;
        s.push(root);
        while(!s.empty()) {
            node* n = s.top();
            s.pop();
            cout << n->val << " ";
            if(n->right != nullptr) s.push(n->right);
            if(n->left != nullptr) s.push(n->left);
        }
    }
    
    void inOrderTraversal(node* root) {
        if(root == nullptr) return ;
        stack<node*> s;
        node* n = root;
        while(!s.empty() || n != nullptr) {
            if(n != nullptr) {
                s.push(n);
                n = n->left;
            }else {
                n = s.top();
                s.pop();
                cout << n->val << " ";
                n = n->right;
            }
        }
    }

    void postOrderTraversal(node* root) {
        if(root == nullptr) return ;
        stack<node*> s1, s2;
        s1.push(root);
        while(!s1.empty()) {
            node* n = s1.top();
            s1.pop();
            s2.push(n);
            if(n->right != nullptr) s1.push(n->right);
            if(n->left != nullptr) s1.push(n->left);
        }
        while(!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    BinaryTreeTraversal solution;

    cout << "前序遍历结果为：";
    solution.preOrderTraversal(root);
    cout << endl;

    cout << "中序遍历结果为：";
    solution.inOrderTraversal(root);
    cout << endl;

    cout << "后序遍历结果为：";
    solution.postOrderTraversal(root);
    cout << endl;

    return 0;
}