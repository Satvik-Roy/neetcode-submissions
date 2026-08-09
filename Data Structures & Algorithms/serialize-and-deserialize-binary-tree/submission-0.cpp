class Codec {
public:
    string serialize(TreeNode* root) {
        string res = "";
        encodeHelper(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decodeHelper(ss);
    }

private:
    void encodeHelper(TreeNode* node, string& res) {
        if (!node) {
            res.append("N,");
            return;
        }
        
        res.append(to_string(node->val)).append(",");
        encodeHelper(node->left, res);
        encodeHelper(node->right, res);
    }

    TreeNode* decodeHelper(stringstream& ss) {
        string token;
        
        getline(ss, token, ',');
        
        if (token == "N") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(token));
        node->left = decodeHelper(ss);
        node->right = decodeHelper(ss);
        
        return node;
    }
};