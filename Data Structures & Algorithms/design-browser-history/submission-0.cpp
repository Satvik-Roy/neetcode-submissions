class BrowserHistory {
private:
    vector<string> history;
    int curr_idx;
    int max_idx;
    
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr_idx = 0;
        max_idx = 0;
    }
    
    void visit(string url) {
        curr_idx++; 
        if (curr_idx < history.size()) {
            history[curr_idx] = url;
        } else {
            history.push_back(url);
        }
        
        max_idx = curr_idx; 
    }
    
    string back(int steps) {
        curr_idx = max(0, curr_idx - steps);
        return history[curr_idx];
    }
    
    string forward(int steps) {
        curr_idx = min(max_idx, curr_idx + steps);
        return history[curr_idx];
    }
};