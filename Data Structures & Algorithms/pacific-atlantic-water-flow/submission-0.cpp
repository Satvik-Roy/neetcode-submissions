class Solution {
    int m, n;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited, int prevHeight) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            dfs(heights, r + dirs[i][0], c + dirs[i][1], visited, heights[r][c]);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int c = 0; c < n; c++) {
            dfs(heights, 0, c, pac, heights[0][c]);
            dfs(heights, m - 1, c, atl, heights[m - 1][c]);
        }

        for (int r = 0; r < m; r++) {
            dfs(heights, r, 0, pac, heights[r][0]);
            dfs(heights, r, n - 1, atl, heights[r][n - 1]);
        }

        vector<vector<int>> res;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};