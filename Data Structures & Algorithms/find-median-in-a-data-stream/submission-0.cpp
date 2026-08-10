class MedianFinder {
private:
    priority_queue<int> maxHeap;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
        if (minHeap.size() > maxHeap.size()) {
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};