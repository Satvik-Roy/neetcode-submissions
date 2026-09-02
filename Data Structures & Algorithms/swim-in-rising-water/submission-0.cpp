class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        while (!minHeap.empty()) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            
            int pathMax = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if (r == n - 1 && c == n - 1) {
                return pathMax;
            }
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    
                    minHeap.push({max(pathMax, grid[nr][nc]), nr, nc});
                }
            }
        }
        
        return -1;
    }
};