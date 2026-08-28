class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        wordList.push_back(beginWord);
        
        unordered_map<string, vector<string>> adj;
        for (string word : wordList) {
            for (int j = 0; j < word.length(); j++) {
                string pattern = word;
                pattern[j] = '*';
                adj[pattern].push_back(word);
            }
        }
        
        queue<string> q;
        unordered_set<string> visit;
        
        q.push(beginWord);
        visit.insert(beginWord);
        int res = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) {
                    return res;
                }
                
                for (int j = 0; j < word.length(); j++) {
                    string pattern = word;
                    pattern[j] = '*';
                    
                    for (string neighbor : adj[pattern]) {
                        if (!visit.count(neighbor)) {
                            visit.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            res++;
        }
        
        return 0;
    }
};