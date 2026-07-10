class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            
            TreeNode* curr = root->right;
            while (curr->left) curr = curr->left;
            
            root->val = curr->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};