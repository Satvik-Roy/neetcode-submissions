class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        dfs(root, globalMax);
        return globalMax;
    }

private:
    int dfs(TreeNode* node, int& globalMax) {
        if (!node) return 0;
        
        int leftMax = max(0, dfs(node->left, globalMax));
        int rightMax = max(0, dfs(node->right, globalMax));
        
        int localMax = node->val + leftMax + rightMax;
        
        globalMax = max(globalMax, localMax);
        
        return node->val + max(leftMax, rightMax);
    }
};