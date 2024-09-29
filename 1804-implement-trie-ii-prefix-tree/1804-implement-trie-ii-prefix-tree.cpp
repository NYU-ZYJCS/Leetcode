struct TrieNode {
    vector<TrieNode*> children;
    int wordsEndingHere = 0;
    int wordsStartingHere = 0;
    
    TrieNode() {
        // Initialize the children vector with 26 nullptrs for each letter 'a' to 'z'
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
            cur->wordsStartingHere++;
        }
        cur->wordsEndingHere++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                return 0;
            }
            cur = cur->children[idx];
        }
        return cur->wordsEndingHere;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                return 0;
            }
            cur = cur->children[idx];
        }
        return cur->wordsStartingHere;
    }
    
    void erase(string word) {
        TrieNode* cur = root;
        for (auto& c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) return;
            
            cur = cur->children[idx];
            cur->wordsStartingHere--;
        }
        cur->wordsEndingHere--;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */