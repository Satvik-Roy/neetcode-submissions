class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                
                if (text1[r] == text2[c]) {
                    dp[r][c] = 1 + dp[r + 1][c + 1];
                } 
                else {
                    dp[r][c] = max(dp[r][c + 1], dp[r + 1][c]);
                }
            }
        }
        
        return dp[0][0];
    }
};