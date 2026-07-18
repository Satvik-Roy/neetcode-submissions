class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    freshCount++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }
        
        int minutes = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty() && freshCount > 0) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshCount--;
                    }
                }
            }
            minutes++;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};