class WordDictionary {
private:
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    bool dfs(int index, TrieNode* node, string& word) {
        if (index == word.length()) {
            return node->isWord;
        }
        
        char c = word[index];
        
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (dfs(index + 1, node->children[i], word)) {
                        return true;
                    }
                }
            }
            return false;
        } 
        else {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            return dfs(index + 1, node->children[idx], word);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }
};