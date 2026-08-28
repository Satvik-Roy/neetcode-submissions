class Solution {
public:
    string longestPalindrome(string s) {
        int resStart = 0;
        int resLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int maxLen = max(len1, len2);
            
            if (maxLen > resLen) {
                resLen = maxLen;
                resStart = i - (maxLen - 1) / 2; 
            }
        }
        
        return s.substr(resStart, resLen);
    }

private:
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};