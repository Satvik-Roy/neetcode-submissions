class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        
        dp[s.length()] = true;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            
            for (string word : wordDict) {
                
                if (i + word.length() <= s.length() && s.substr(i, word.length()) == word) {
                    
                    dp[i] = dp[i + word.length()];
                }
                
                if (dp[i]) {
                    break;
                }
            }
        }
        
        return dp[0];
    }
};