#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.cpp"
using namespace std;

// N叉树的前序遍历

class Solution_for_589_preorder {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr) return res;
        // 因为第一次遍历到结点就要放进res中
        res.push_back(root->val);
        for(auto child : root->children) {
            // 这里的结果一定要放进res中
            vector<int> temp = preorder(child);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};

class Solution2_for_589_preorder {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<pair<Node*, bool>> st;
        st.emplace(root, true);
        while(!st.empty()) {
            Node* curNode = st.top().first;
            bool visited = st.top().second;
            st.pop();
            res.push_back(curNode->val);
            // 注意前序遍历是从左到右的顺序，放入栈的时候从右到左
            for(int i = curNode->children.size()-1; i >= 0; --i) {
                st.emplace(curNode->children[i], true);
            }
        }
        return res;
    }
};
