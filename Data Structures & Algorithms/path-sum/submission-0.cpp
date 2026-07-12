class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }
        
        int remainingTarget = targetSum - root->val;
        
        return hasPathSum(root->left, remainingTarget) || 
               hasPathSum(root->right, remainingTarget);
    }
};