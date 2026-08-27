class Solution {
    bool dfs(int crs, vector<vector<int>>& adj, vector<int>& state, vector<int>& res) {
        if (state[crs] == 1) return false;
        
        if (state[crs] == 2) return true;
        
        state[crs] = 1;
        
        for (int pre : adj[crs]) {
            if (!dfs(pre, adj, state, res)) return false;
        }
        
        state[crs] = 2;
        
        res.push_back(crs);
        
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        
        vector<int> state(numCourses, 0);
        vector<int> res;
        
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state, res)) {
                    return {};
                }
            }
        }
        
        return res;
    }
};