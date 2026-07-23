class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> used;
        for (int num : nums) {
            if (used.count(num)) {
                return true;
            }
            used.insert(num);
        }
        return false;
    }
};