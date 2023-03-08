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