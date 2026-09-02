class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool> visited(n, false);
        
        int totalCost = 0;
        int connectedNodes = 0;
        
        minHeap.push({0, 0});
        
        while (!minHeap.empty() && connectedNodes < n) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            
            if (visited[node]) {
                continue;
            }
            
            visited[node] = true;
            totalCost += cost;
            connectedNodes++;
            
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    minHeap.push({dist, i});
                }
            }
        }
        
        return totalCost;
    }
};