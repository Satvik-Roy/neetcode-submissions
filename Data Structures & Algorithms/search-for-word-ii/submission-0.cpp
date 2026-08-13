class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
    int m, n;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<string> res;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        
        char ch = board[r][c];
        
        if (ch == '#' || node->children[ch - 'a'] == nullptr) return;

        node = node->children[ch - 'a'];
        word += ch;

        if (node->isWord) {
            res.push_back(word);
            node->isWord = false;
        }

        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            dfs(board, r + dirs[i][0], c + dirs[i][1], node, word);
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        TrieNode* root = new TrieNode();
        for (string w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c - 'a'];
            }
            curr->isWord = true;
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfs(board, r, c, root, "");
            }
        }

        return res;
    }
};