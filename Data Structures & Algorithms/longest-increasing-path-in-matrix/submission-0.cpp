class Solution {
    int m, n;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int dfs(vector<vector<int>>& matrix, int r, int c, int prevVal, vector<vector<int>>& memo) {
        if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= prevVal) {
            return 0;
        }

        if (memo[r][c] > 0) {
            return memo[r][c];
        }

        int res = 1;

        for (int i = 0; i < 4; i++) {
            res = max(res, 1 + dfs(matrix, r + dirs[i][0], c + dirs[i][1], matrix[r][c], memo));
        }

        memo[r][c] = res;
        return res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int longestPath = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                longestPath = max(longestPath, dfs(matrix, r, c, -1, memo));
            }
        }

        return longestPath;
    }
};