class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        
        int dirs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        int pathLength = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                if (r == n - 1 && c == n - 1) return pathLength;
                
                for (int d = 0; d < 8; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            pathLength++;
        }
        
        return -1; 
    }
};