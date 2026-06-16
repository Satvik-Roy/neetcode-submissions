class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> result(26);
        for(int i = 0; i < s.length(); i++)
        {
            result[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++)
        {
            result[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(result[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};