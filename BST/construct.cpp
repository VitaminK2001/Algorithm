#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BST{
public:
    TreeNode* root;

    void insert(int val) {
        if(!root) {
            root = new TreeNode(val);
            return ;
        }
        TreeNode* curr = root;
        while(curr) {
            if(val < curr->val) {
                if(curr->left) {
                    curr = curr->left;
                }else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }else {
                if(curr->right) {
                    curr = curr->right;
                }else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
    }

    TreeNode* search(int val) {
        TreeNode* curr = root;
        while(curr) {
            if(val == curr->val) {
                return curr;
            }else if(val < curr->val) {
                curr = curr->left;
            }else {
                curr = curr->right;
            }
        }
        return NULL;
    }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);

    cout << tree.search(7)->val << endl;  // 输出 7

    return 0;
}