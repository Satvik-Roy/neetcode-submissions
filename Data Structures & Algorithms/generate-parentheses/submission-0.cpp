class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        
        dfs(0, 0, n, curr, res);
        
        return res;
    }

private:
    void dfs(int openCount, int closedCount, int n, string& curr, vector<string>& res) {
        if (openCount == n && closedCount == n) {
            res.push_back(curr);
            return;
        }
        
        if (openCount < n) {
            curr.push_back('(');
            dfs(openCount + 1, closedCount, n, curr, res);
            curr.pop_back();
        }
        
        if (closedCount < openCount) {
            curr.push_back(')');
            dfs(openCount, closedCount + 1, n, curr, res);
            curr.pop_back();
        }
    }
};