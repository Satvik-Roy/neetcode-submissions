class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {
    }
    
    void push(int x) {
        int currentSize = q.size();
        
        q.push(x);
        
        for (int i = 0; i < currentSize; i++) {
            int frontElement = q.front();
            q.pop();
            q.push(frontElement);
        }
    }
    
    int pop() {
        int topVal = q.front();
        q.pop();
        return topVal;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};