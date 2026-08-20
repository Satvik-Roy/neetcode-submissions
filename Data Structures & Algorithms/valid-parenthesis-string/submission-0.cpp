class Solution {
public:
    bool checkValidString(string s) {
        int cMin = 0;
        int cMax = 0;
        
        for (char c : s) {
            if (c == '(') {
                cMin++;
                cMax++;
            } else if (c == ')') {
                cMin--;
                cMax--;
            } else {
                cMin--;
                cMax++;
            }
            
            if (cMax < 0) {
                return false; 
            }
            
            if (cMin < 0) {
                cMin = 0;
            }
        }
        
        return cMin == 0;
    }
};