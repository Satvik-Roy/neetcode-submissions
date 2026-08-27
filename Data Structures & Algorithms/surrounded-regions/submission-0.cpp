class Solution {
    int m, n;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';

        for (int i = 0; i < 4; i++) {
            dfs(board, r + dirs[i][0], c + dirs[i][1]);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size();
        n = board[0].size();

        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[m - 1][c] == 'O') dfs(board, m - 1, c);
        }

        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][n - 1] == 'O') dfs(board, r, n - 1);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};