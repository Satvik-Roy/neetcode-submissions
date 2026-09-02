class Solution {
    bool dfs(char c, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, int>& state, string& res) {
        if (state[c] == 1) return false;
        if (state[c] == 2) return true;
        
        state[c] = 1;
        
        for (char neighbor : adj[c]) {
            if (!dfs(neighbor, adj, state, res)) return false;
        }
        
        state[c] = 2;
        res.push_back(c);
        
        return true;
    }

public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> state;
        
        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                state[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2) {
                return "";
            }
            
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        
        string res = "";
        for (auto& pair : state) {
            char c = pair.first;
            if (state[c] == 0) {
                if (!dfs(c, adj, state, res)) {
                    return "";
                }
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};