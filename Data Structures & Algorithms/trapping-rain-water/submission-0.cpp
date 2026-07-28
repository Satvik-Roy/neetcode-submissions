class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        int maxLeft = height[left];
        int maxRight = height[right];
        
        int totalWater = 0;
        
        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                totalWater += maxLeft - height[left];
            } 
            else {
                right--;
                maxRight = max(maxRight, height[right]);
                totalWater += maxRight - height[right];
            }
        }
        
        return totalWater;
    }
};