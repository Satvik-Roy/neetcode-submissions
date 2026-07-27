class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        
        for (const string& word : strs) {
            // Format: [Length] + [#] + [Word]
            encoded += to_string(word.length()) + "#" + word;
        }
        
        return encoded;
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