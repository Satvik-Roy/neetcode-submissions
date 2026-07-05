class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), res=0;
        for (int i = 0; i<n; i++){
            int count = 0;
            for (int j=i; j<n; j++){
                if (nums[j]==0) break;
                count++;
            }
            res = max (res, count);
        }
        return res;
        
    }
};