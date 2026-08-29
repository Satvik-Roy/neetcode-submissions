class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        int dp1 = 1;
        int dp2 = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int currentWays = 0;
            
            if (s[i] != '0') {
                currentWays += dp1;
            }
            
            if (i + 1 < n) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                    currentWays += dp2;
                }
            }
            
            dp2 = dp1;
            dp1 = currentWays;
        }
        
        return dp1;
    }
};