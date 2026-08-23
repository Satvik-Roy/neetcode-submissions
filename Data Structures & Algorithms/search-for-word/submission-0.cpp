class Solution {
    int m, n;
    
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int wordIndex) {
        if (wordIndex == word.length()) {
            return true;
        }
        
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[wordIndex]) {
            return false;
        }
                
        char temp = board[r][c];
        board[r][c] = '#';
        
        bool found = dfs(board, r + 1, c, word, wordIndex + 1) ||
                     dfs(board, r - 1, c, word, wordIndex + 1) ||
                     dfs(board, r, c + 1, word, wordIndex + 1) ||
                     dfs(board, r, c - 1, word, wordIndex + 1);
                     
        board[r][c] = temp;
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, r, c, word, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};