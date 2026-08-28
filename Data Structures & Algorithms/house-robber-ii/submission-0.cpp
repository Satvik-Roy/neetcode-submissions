class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    int robLinear(vector<int>& nums, int start, int end) {
        int rob1 = 0;
        int rob2 = 0;
        
        for (int i = start; i <= end; i++) {
            int currentMax = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = currentMax;
        }
        
        return rob2;
    }
};