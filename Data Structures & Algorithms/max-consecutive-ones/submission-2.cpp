class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, cnt=0;
        for (int num : nums){
            if (num==0){
                res=max(res,cnt);
                cnt=0;
            } else {
                cnt++;
            }
        }
        return max(cnt, res);
    }
};