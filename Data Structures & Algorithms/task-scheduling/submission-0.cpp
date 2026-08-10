class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        
        priority_queue<int> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                maxHeap.push(count[i]);
            }
        }
        
        queue<pair<int, int>> q;
        int time = 0;
        
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            
            if (!maxHeap.empty()) {
                int remainingFreq = maxHeap.top() - 1;
                maxHeap.pop();
                
                if (remainingFreq > 0) {
                    q.push({remainingFreq, time + n});
                }
            }
            
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first); // Put it back in the heap!
                q.pop();
            }
        }
        
        return time;
    }
};