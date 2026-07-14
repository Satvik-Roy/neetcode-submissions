class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-Heap storing pairs: {squared_distance, point_coordinates}
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (auto& point : points) {
            int dist = (point[0] * point[0]) + (point[1] * point[1]);
            maxHeap.push({dist, point});
            
            // If the club gets too big, kick out the farthest point!
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Extract the remaining K closest points from the heap
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second); // .second holds the coordinates
            maxHeap.pop();
        }
        
        return res;
    }
};