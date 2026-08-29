class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int res = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            
            if (n < 0) {
                swap(curMax, curMin);
            }
            
            curMax = max(n, curMax * n);
            curMin = min(n, curMin * n);
            
            res = max(res, curMax);
        }
        
        return res;
    }
};