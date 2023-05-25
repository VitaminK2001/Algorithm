#include <iostream>
#include "TreeNode.cpp"
using namespace std;

/* 将原树中结点的值 变成原树中大于或等于node.val的值之和 */
class Solution_for_538 {
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

// Morris中序遍历
class Solution2_for_538 {
public:
    // 通过建立前驱结点和当前节点的联系，这样在遍历完前驱结点后 会自动回到当前节点
    // 而每次遍历当前节点的时候 都去搜索前驱结点，如果前驱结点有指向当前节点的指针，说明当前节点的左子树已经遍历完了（因为前驱结点是当前节点左子树在中序遍历中最后一个遍历的结点）
    // 如果没有，则建立指针从前驱结点指向当前节点，并往左子树的方向走
    void MorrisTraversal(TreeNode *root) {
        TreeNode *node = root;
        // while中的遍历过程需要重复道指针为空
        while(node != nullptr) {
            if(node->left == nullptr) { // 如果左子树为空
                cout << node->val << " ";
                node = node->right;
            }else { // 左子树不为空
                // 找到左子树最右边的结点 这个结点就是当前节点在中序遍历中的前驱结点
                TreeNode *pre = node->left;
                while(pre->right != nullptr && pre->right != node) { // 如果已经遍历到最右边的结点 或者 遍历到当前节点（已经线索化了） 就跳出循环
                    pre = pre->right;
                }
                if(pre->right == NULL) { //如果已经是最右边的结点
                    pre->right = node;   // 线索化
                    node = node->left;  // 往左子树的方向走
                }else { // 如果已经线索化了
                    pre->right = nullptr; // 恢复树的形状(因为当前节点的整个左子树已经遍历完)
                    cout << node->val << " "; // 遍历当前节点
                    node = node->right; // 遍历当前节点的右子树
                }   
            }
        }
    }
    void MorrisInOrderTravesal(TreeNode *root) {
        TreeNode *cur = root;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                cout << cur->val << " ";
                cur = cur->right;
            }else {
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur) {
                    node = node->right;
                }
                if(node->right == nullptr) {
                    node->right = cur;
                    node = node->left;
                }else {
                    
                }
            }
        }
    }

    void MorrisPreOrderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                cout << cur->val << endl;
                cur = cur->right;
            }else {
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur) {
                    node = node->right;
                }
                if(node->right == nullptr) {
                    cout << cur->val << endl;
                    node->right = cur;
                    cur = cur->left;
                }else {
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
    }

    // 本题中的要求是反向中序遍历二叉搜索树 
    // 因为要将大于等于当前节点的点先遍历 并求和，才能知道当前节点应该赋值为多少
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode *node = root;
        while(node != nullptr) {
            if(node->right == nullptr) {
                // 说明已经遍历完右子树 此时可以对当前结点进行赋值
                sum += node->val;
                node->val = sum;
                node = node->left;
            }else {
                // 说明还没有遍历完右子树 不能对当前节点进行赋值
                // 在右子树中找最左边的结点，是当前节点的前驱结点
                TreeNode *pre = node->right;
                while(pre->left != nullptr && pre->left != node) {
                    pre = pre->left;
                }
                if(pre->left == nullptr) {
                    pre->left = node;
                    node = node->right;
                }else {
                    // 说明整个右子树已经遍历完 此时可以对当前结点进行赋值
                    pre->left = nullptr; // 恢复树的形状
                    sum += node->val;
                    node->val = sum;
                    node = node->left; // 遍历左子树
                }
            }
        }
        return root;
    }
};