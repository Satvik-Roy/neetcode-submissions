class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        
        int n = intervals.size();
        vector<int> starts(n);
        vector<int> ends(n);
        
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int s = 0, e = 0;
        int count = 0, maxRooms = 0;
        
        while (s < n) {
            if (starts[s] < ends[e]) {
                count++;
                s++;
            } 
            else {
                count--;
                e++;
            }
            
            maxRooms = max(maxRooms, count);
        }
        
        return maxRooms;
    }
};