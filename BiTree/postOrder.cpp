#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include "TreeNode.cpp"

using namespace std;

class Solution_for_652_findDuplicateSubtrees{
public:
    unordered_map<string, int> memo;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return res;
    }
    string traversal(TreeNode* root) {
        if(root == nullptr) {
            return "#"; //结束符
        }
        string left = traversal(root->left);
        string right = traversal(root->right);
        string subTree = left + "," + right + "," + to_string(root->val);
        if(memo[subTree] == 1) {
            res.push_back(root);
        }
        memo[subTree]++;
        return subTree;
    }
};

class Solution_for_543_diameterOfBinaryTree {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        dfs(root, diameter);
        return diameter;
    }
    int dfs(TreeNode* root, int& diameter) {
        if(root == nullptr) return 0;

        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        int length = left + right;
        diameter = max(diameter, length); 

        return 1 + max(left, right);
    }
};

// 多叉树的定义
class Node{
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

class Solution_for_590_postorder {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) {
            return res;
        }
        for(auto child : root->children) {
            vector<int> temp = postorder(child);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        // 如果这个root是叶子节点
        res.push_back(root->val);
        return res;
    }
};

class Solution2_for_590_postorder {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<pair<Node*, bool>> st;
        st.emplace(root, false);
        while(!st.empty()) {
            Node* node = st.top().first;
            bool visit = st.top().second;
            st.pop();
            if(visit) {
                // 如果是第二次访问
                res.push_back(node->val);
            }else {
                // 如果是第一次访问，重新放回等待第二次访问
                st.emplace(node, true); 
                for(int i = 0; i < node->children.size(); ++i) {
                    st.emplace(node->children[i], false);
                }
            }
        }
    }
};