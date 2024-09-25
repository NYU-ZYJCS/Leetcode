struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int score;
    
    TrieNode() : score(0) {}
};

class Trie {
public:
    TrieNode* root;
    
    Trie() { root = new TrieNode(); }
    
    void insert(const string& word) {
        TrieNode* cur = root;
        
        for (auto c : word) {
            if (!cur->children.contains(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            ++cur->score;
        }
    }
    
    int search(const string& word) {
        TrieNode* cur = root;
        int ans = 0;
        
        for (auto c : word) {
            cur = cur->children[c];
            if (cur == nullptr) break;
            ans += cur->score;
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        
        for (auto word : words) trie.insert(word);
        
        vector<int> ans;
        for (auto word : words) {
            ans.push_back(trie.search(word));
        }
        
        return ans;
    }
};