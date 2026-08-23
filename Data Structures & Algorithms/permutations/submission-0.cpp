class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        
        dfs(nums, curr, used, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (used[i]) {
                continue;
            }
            
            used[i] = true;
            curr.push_back(nums[i]);
            
            dfs(nums, curr, used, res);
            
            curr.pop_back();
            used[i] = false;
        }
    }
};