class Solution {
    unordered_map<string, int> memo;

    int dfs(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target ? 1 : 0;
        }

        string key = to_string(i) + "," + to_string(total);
        if (memo.count(key)) {
            return memo[key];
        }

        int add = dfs(i + 1, total + nums[i], nums, target);
        int sub = dfs(i + 1, total - nums[i], nums, target);

        memo[key] = add + sub;
        
        return memo[key];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }
};