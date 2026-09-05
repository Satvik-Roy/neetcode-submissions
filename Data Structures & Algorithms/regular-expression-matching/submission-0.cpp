class Solution {
    vector<vector<int>> memo;

    bool dfs(int i, int j, string& s, string& p) {
        if (i >= s.length() && j >= p.length()) {
            return true;
        }
        
        if (j >= p.length()) {
            return false;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }
        
        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        
        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool res = dfs(i, j + 2, s, p) || 
                       (match && dfs(i + 1, j, s, p));
            
            memo[i][j] = res ? 1 : 0;
            return res;
        }
        
        if (match) {
            bool res = dfs(i + 1, j + 1, s, p);
            memo[i][j] = res ? 1 : 0;
            return res;
        }
        
        memo[i][j] = 0;
        return false;
    }

public:
    bool isMatch(string s, string p) {
        memo.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        
        return dfs(0, 0, s, p);
    }
};