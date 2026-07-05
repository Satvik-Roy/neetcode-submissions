class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            int currentMin = minStack.top();
            int newMin = std::min(val, currentMin);
            minStack.push(newMin);
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};