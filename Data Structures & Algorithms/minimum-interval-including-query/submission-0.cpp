class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> res(queries.size(), -1);
        int i = 0;
        
        for (auto& q : sortedQueries) {
            int queryVal = q.first;
            int originalIdx = q.second;
            
            while (i < intervals.size() && intervals[i][0] <= queryVal) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++; 
            }
            
            while (!minHeap.empty() && minHeap.top().second < queryVal) {
                minHeap.pop();
            }
            
            if (!minHeap.empty()) {
                res[originalIdx] = minHeap.top().first; // .first is the size
            }
        }
        
        return res;
    }
};