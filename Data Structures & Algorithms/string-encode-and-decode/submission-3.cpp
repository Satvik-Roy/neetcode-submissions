class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            int delimPos = s.find('#', i);
            
            int wordLen = stoi(s.substr(i, delimPos - i));
            
            string word = s.substr(delimPos + 1, wordLen);
            decoded.push_back(word);
            
            i = delimPos + 1 + wordLen;
        }
        
        return decoded;
    }
};