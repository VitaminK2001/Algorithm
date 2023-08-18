#include <stack>
#include <iostream>
#include <queue>
#include "TreeNode.cpp"
using namespace std;
/*
    author: vchici
    通过非递归方法三种遍历二叉树 + 层序遍历二叉树
*/
class Traversal{
public:
    void preOrder(TreeNode* root) {
        if(root == nullptr) return ;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* curNode = st.top();
            st.pop();
            cout << curNode->val << " ";
            if(curNode->right != nullptr) st.push(curNode->right);
            if(curNode->left != nullptr) st.push(curNode->left);
        }
    }

    void inOrder(TreeNode* root) {
        if(root == nullptr) return ;
        stack<TreeNode*> st;
        TreeNode* n = root;
        while(!st.empty() || n != nullptr) {
            if(n != nullptr) { // 重点注意:不能判断n->left != nullptr 因为n可能为空
                // 说明左子树还没有遍历完，不能访问
                // 不能访问也就是指不能pop 只能push(遍历)
                st.push(n);
                n = n->left;
            }else {
                // 说面左子树已经遍历完，可以访问
                n = st.top();
                st.pop();
                cout << n->val << " ";
                // 访问完根节点以后，再遍历右子树
                n = n->right;
            }
        }
    }

    void postOrder(TreeNode* root) {
        if(root == nullptr) return ;
        // 后序遍历就是前序遍历的倒序，通过栈倒置一下顺序就好
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode* curNode = s1.top();
            s1.pop();
            s2.push(curNode);
            if(curNode->right != nullptr) s1.push(curNode->right);
            if(curNode->left != nullptr) s1.push(curNode->left);
        }
        while(!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }

    void levelTraversal(TreeNode* root){
        if(root == nullptr) return ;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* n = q.front();
                q.pop();
                cout << n->val << " ";
                if(n->left != nullptr) q.push(n->left);
                if(n->right != nullptr) q.push(n->right);
            }
        }
    }

    // 自下而上 自右向左遍历二叉树
    void backwards_levelTraversal(TreeNode* root){
        if(root == nullptr) return ;
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        q.push(root);
        while(!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            st.push(n);
            if(n->left != nullptr) q.push(n->left);
            if(n->right != nullptr) q.push(n->right);
        }
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            cout << cur->val << " ";
        }
        cout << endl;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Traversal solution;

    cout << "前序遍历结果为：";
    solution.preOrder(root);
    cout << endl;

    cout << "中序遍历结果为：";
    solution.inOrder(root);
    cout << endl;

    cout << "后序遍历结果为：";
    solution.postOrder(root);
    cout << endl;

    cout << "层次遍历结果为：";
    solution.levelTraversal(root);
    cout << endl;

    cout << "反层次遍历结果为: ";
    solution.backwards_levelTraversal(root);
    cout << endl;

    return 0;
}

// 前序遍历结果为：1 2 4 5 3 6 
// 中序遍历结果为：4 2 5 1 3 6 
// 后序遍历结果为：6 3 5 4 2 1 
// 层次遍历结果为：1 2 3 4 5 6 
// 反层次遍历结果为: 6 5 4 3 2 1 