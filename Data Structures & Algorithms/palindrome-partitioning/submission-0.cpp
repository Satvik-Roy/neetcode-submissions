class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(0, s, curr, res);
        return res;
    }

private:
    void dfs(int index, string& s, vector<string>& curr, vector<vector<string>>& res) {
        if (index == s.length()) {
            res.push_back(curr);
            return;
        }
        
        for (int j = index; j < s.length(); j++) {
            
            if (isPalindrome(s, index, j)) {
                
                curr.push_back(s.substr(index, j - index + 1));
                
                dfs(j + 1, s, curr, res);
                
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};