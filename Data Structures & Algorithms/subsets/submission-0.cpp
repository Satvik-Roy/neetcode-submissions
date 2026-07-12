class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, nums, curr, res);
        return res;
    }

private:
    void dfs(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(i + 1, nums, curr, res);

        curr.pop_back();
        dfs(i + 1, nums, curr, res);
    }
};