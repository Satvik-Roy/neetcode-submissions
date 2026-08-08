class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool dfs(TreeNode* node, long long leftBoundary, long long rightBoundary) {
        if (!node) return true;
        
        if (node->val <= leftBoundary || node->val >= rightBoundary) {
            return false;
        }
        
        bool leftValid = dfs(node->left, leftBoundary, node->val);
        
        bool rightValid = dfs(node->right, node->val, rightBoundary);
        
        return leftValid && rightValid;
    }
};