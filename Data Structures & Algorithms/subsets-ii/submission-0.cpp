class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        sort(nums.begin(), nums.end());
        
        dfs(0, nums, curr, res);
        return res;
    }

private:
    void dfs(int startIndex, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        
        for (int i = startIndex; i < nums.size(); i++) {
            
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            
            curr.push_back(nums[i]);
            
            dfs(i + 1, nums, curr, res);
            
            curr.pop_back();
        }
    }
};