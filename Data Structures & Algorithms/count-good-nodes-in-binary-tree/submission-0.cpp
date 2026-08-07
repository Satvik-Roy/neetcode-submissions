class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        
        int res = (node->val >= maxSoFar) ? 1 : 0;
        
        maxSoFar = max(maxSoFar, node->val);
        
        res += dfs(node->left, maxSoFar);
        res += dfs(node->right, maxSoFar);
        
        return res;
    }
};