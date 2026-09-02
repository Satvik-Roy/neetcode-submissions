class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> res;

    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string nextAirport = adj[airport].top();
            adj[airport].pop();
            
            dfs(nextAirport);
        }
        
        res.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }
        
        dfs("JFK");
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};