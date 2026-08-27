class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            int currentDist = grid[r][c];
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = currentDist + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};