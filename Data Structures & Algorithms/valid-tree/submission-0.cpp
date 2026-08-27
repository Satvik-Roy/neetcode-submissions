class Solution {
    bool dfs(int node, int prev, vector<vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(node)) return false;
        
        visited.insert(node);
        
        for (int neighbor : adj[node]) {
            if (neighbor == prev) continue;
            
            if (!dfs(neighbor, node, adj, visited)) return false;
        }
        
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        
        if (!dfs(0, -1, adj, visited)) {
            return false;
        }
        
        return visited.size() == n;
    }
};