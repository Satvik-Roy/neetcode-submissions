class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int infinity = amount + 1;
        vector<int> dp(amount + 1, infinity);
        
        dp[0] = 0;
        
        for (int a = 1; a <= amount; a++) {
            
            for (int coin : coins) {
                if (a - coin >= 0) {
                    dp[a] = min(dp[a], 1 + dp[a - coin]);
                }
            }
        }
        return dp[amount] == infinity ? -1 : dp[amount];
    }
};