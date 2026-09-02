class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_set<int> visited;
        int maxTime = 0;
        
        minHeap.push({0, k});
        
        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();
            
            if (visited.count(node)) {
                continue;
            }
            
            visited.insert(node);
            maxTime = max(maxTime, time);
            
            if (visited.size() == n) {
                return maxTime;
            }
            
            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;
                
                if (!visited.count(neighbor)) {
                    minHeap.push({time + weight, neighbor});
                }
            }
        }
        
        return -1;
    }
};