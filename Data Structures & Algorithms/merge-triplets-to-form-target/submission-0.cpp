class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundA = false, foundB = false, foundC = false;
        
        for (auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }
            
            if (t[0] == target[0]) foundA = true;
            if (t[1] == target[1]) foundB = true;
            if (t[2] == target[2]) foundC = true;
        }
        
        return foundA && foundB && foundC;
    }
};