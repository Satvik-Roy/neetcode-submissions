class Solution {
    int m, n;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') return;
        
        grid[r][c] = '0';
        
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dirs[i][0], c + dirs[i][1]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        int islandCount = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    islandCount++;
                    dfs(grid, r, c);
                }
            }
        }
        
        return islandCount;
    }
};
