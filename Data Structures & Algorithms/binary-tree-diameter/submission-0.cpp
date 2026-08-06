class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        dfs(root, max_diameter);
        return max_diameter;
    }

private:
    int dfs(TreeNode* root, int& max_diameter) {
        if (!root) return 0;
        
        int leftH = dfs(root->left, max_diameter);
        int rightH = dfs(root->right, max_diameter);
        
        max_diameter = max(max_diameter, leftH + rightH);
        
        return 1 + max(leftH, rightH);
    }
};