class Solution {
    bool dfs(int crs, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[crs] == 1) return false;
        
        if (adj[crs].empty()) return true;
        
        visited[crs] = 1;
        
        for (int pre : adj[crs]) {
            if (!dfs(pre, adj, visited)) return false;
        }
        
        visited[crs] = 0;
        
        adj[crs].clear();
        
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, visited)) {
                return false;
            }
        }
        
        return true;
    }
};