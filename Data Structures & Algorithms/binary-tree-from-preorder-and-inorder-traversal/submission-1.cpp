class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        int preIdx = 0;
        return build(preorder, 0, inorder.size() - 1, inMap, preIdx);
    }

private:
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd, unordered_map<int, int>& inMap, int& preIdx) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        
        root->left = build(preorder, inStart, mid - 1, inMap, preIdx);
        root->right = build(preorder, mid + 1, inEnd, inMap, preIdx);
        
        return root;
    }
};