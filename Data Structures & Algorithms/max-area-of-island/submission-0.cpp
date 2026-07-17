class Solution {
    int m, n;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        
        grid[r][c] = 0;
        int area = 1;
        
        for (int i = 0; i < 4; i++) {
            area += dfs(grid, r + dirs[i][0], c + dirs[i][1]);
        }
        
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(grid, r, c));
                }
            }
        }
        
        return maxArea;
    }
};