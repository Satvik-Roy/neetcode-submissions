class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0; // Max money up to 2 houses ago
        int rob2 = 0; // Max money up to 1 house ago
        
        for (int num : nums) {
            // Choice A: Rob this house (num + rob1)
            // Choice B: Skip this house (rob2)
            int currentMax = max(num + rob1, rob2);
            
            // Slide the window forward for the next house
            rob1 = rob2;
            rob2 = currentMax;
        }
        
        // At the end of the street, rob2 holds the maximum possible loot
        return rob2;
    }
};