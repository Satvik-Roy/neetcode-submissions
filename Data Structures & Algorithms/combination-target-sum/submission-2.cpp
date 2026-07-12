class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, curr, 0, nums, target, res);
        return res;
    }
    
private:
    void dfs(int i, vector<int>& curr, int total, vector<int>& nums, int target, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(curr);
            return;
        }
        if (total > target || i >= nums.size()) {
            return;
        }
        
        curr.push_back(nums[i]);
        dfs(i, curr, total + nums[i], nums, target, res); 
        
        curr.pop_back();
        dfs(i + 1, curr, total, nums, target, res);
    }
};