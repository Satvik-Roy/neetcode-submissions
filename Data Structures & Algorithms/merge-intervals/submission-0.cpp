class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            
            vector<int>& lastAdded = res.back();
            
            if (intervals[i][0] <= lastAdded[1]) {
                lastAdded[1] = max(lastAdded[1], intervals[i][1]);
            } 
            else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};