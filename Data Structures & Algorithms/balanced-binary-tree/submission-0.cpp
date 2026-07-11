class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = dfs(root->left);
        if (leftHeight == -1) return -1; 
        
        int rightHeight = dfs(root->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        return 1 + max(leftHeight, rightHeight);
    }
};