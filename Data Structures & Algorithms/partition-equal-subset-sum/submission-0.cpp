class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        unordered_set<int> dp;
        dp.insert(0);

        for (int num : nums) {
            unordered_set<int> nextDP; 
            
            for (int t : dp) {
                if (t + num == target) return true;
                
                if (t + num < target) nextDP.insert(t + num);
                
                nextDP.insert(t);
            }
            
            dp = nextDP;
        }
        
        return dp.count(target);
    }
};