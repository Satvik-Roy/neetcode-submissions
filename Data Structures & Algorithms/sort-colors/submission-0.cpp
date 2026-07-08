class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0, 0, 0}; 
        
        for (int num : nums) counts[num]++;
        
        int index = 0;
        for (int color = 0; color < 3; color++) {
            for (int i = 0; i < counts[color]; i++) {
                nums[index++] = color;
            }
        }
    }
};