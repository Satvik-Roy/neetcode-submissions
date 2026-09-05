class Solution {
    int dfs(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (left > right) return 0;
        
        if (memo[left][right] != 0) return memo[left][right];
        
        int maxCoins = 0;
        
        for (int i = left; i <= right; i++) {
            
            int coins = nums[left - 1] * nums[i] * nums[right + 1];
            
            coins += dfs(left, i - 1, nums, memo) + dfs(i + 1, right, nums, memo);
            
            maxCoins = max(maxCoins, coins);
        }
        
        memo[left][right] = maxCoins;
        return maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        vector<int> paddedNums;
        paddedNums.push_back(1);
        for (int n : nums) paddedNums.push_back(n);
        paddedNums.push_back(1);
        
        int n = nums.size();
        
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));
        
        return dfs(1, n, paddedNums, memo);
    }
};