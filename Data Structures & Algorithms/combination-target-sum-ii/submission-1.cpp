class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        
        sort(candidates.begin(), candidates.end());
        
        dfs(0, target, curr, candidates, res);
        return res;
    }

private:
    void dfs(int startIndex, int target, vector<int>& curr, vector<int>& candidates, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++) {
            
            if (candidates[i] > target) {
                break;
            }
            
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            curr.push_back(candidates[i]);
            
            dfs(i + 1, target - candidates[i], curr, candidates, res);
            
            curr.pop_back();
        }
    }
};