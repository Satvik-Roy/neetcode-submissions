class Solution {
    const string pad[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> res;
        string curr = "";
        
        dfs(0, digits, curr, res);
        return res;
    }

private:
    void dfs(int index, string& digits, string& curr, vector<string>& res) {
        if (index == digits.length()) {
            res.push_back(curr);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = pad[digit];
        
        for (char c : letters) {
            curr.push_back(c);
            
            dfs(index + 1, digits, curr, res);
            
            curr.pop_back();
        }
    }
};