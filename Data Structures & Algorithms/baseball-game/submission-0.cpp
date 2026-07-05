class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        
        for (string op : operations) {
            
            if (op == "C") {
                scores.pop_back();
            } 
            else if (op == "D") {
                int last_score = scores.back();
                scores.push_back(2 * last_score);
            } 
            else if (op == "+") {
                int last = scores[scores.size() - 1];
                int second_last = scores[scores.size() - 2];
                scores.push_back(last + second_last);
            } 
            else {
                int score = stoi(op);
                scores.push_back(score);
            }
        }
        
        int totalSum = 0;
        for (int score : scores) {
            totalSum += score;
        }
        
        return totalSum;
    }
};