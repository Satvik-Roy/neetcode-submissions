class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) return "";

        vector<int> targetCount(128, 0);
        vector<int> windowCount(128, 0);
        
        int need = 0;
        for (char c : t) {
            if (targetCount[c] == 0) need++;
            targetCount[c]++;
        }

        int have = 0;
        int left = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        for (int right = 0; right < s.length(); right++) {
            char rChar = s[right];
            windowCount[rChar]++;

            if (targetCount[rChar] > 0 && windowCount[rChar] == targetCount[rChar]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                char lChar = s[left];
                windowCount[lChar]--;

                if (targetCount[lChar] > 0 && windowCount[lChar] < targetCount[lChar]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};