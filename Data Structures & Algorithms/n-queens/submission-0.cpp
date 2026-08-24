class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> posDiag(2 * n, false); 
        vector<bool> negDiag(2 * n, false); 
        
        dfs(0, n, cols, posDiag, negDiag, board, res);
        return res;
    }

private:
    void dfs(int r, int n, vector<bool>& cols, vector<bool>& posDiag, vector<bool>& negDiag, vector<string>& board, vector<vector<string>>& res) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            
            int posSignature = r + c;
            int negSignature = (r - c) + n;
            
            if (cols[c] || posDiag[posSignature] || negDiag[negSignature]) {
                continue;
            }
            
            cols[c] = true;
            posDiag[posSignature] = true;
            negDiag[negSignature] = true;
            board[r][c] = 'Q';
            
            dfs(r + 1, n, cols, posDiag, negDiag, board, res);
            
            cols[c] = false;
            posDiag[posSignature] = false;
            negDiag[negSignature] = false;
            board[r][c] = '.';
        }
    }
};