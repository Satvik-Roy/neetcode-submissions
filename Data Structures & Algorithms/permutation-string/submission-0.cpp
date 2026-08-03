class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        if (len1 > len2) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        for (int i = 0; i < len1; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        
        if (s1Count == s2Count) return true;
        
        int left = 0;
        for (int right = len1; right < len2; right++) {
            s2Count[s2[right] - 'a']++;
            
            s2Count[s2[left] - 'a']--;
            left++;
            
            if (s1Count == s2Count) return true;
        }
        
        return false;
    }
};