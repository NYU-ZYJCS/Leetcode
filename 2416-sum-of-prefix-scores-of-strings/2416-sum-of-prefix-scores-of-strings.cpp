struct TrieNode {
    vector<TrieNode*> children;
    int score;
    
    TrieNode() : children(26, nullptr), score(0) {}
};

class Trie {
public:
    TrieNode* root;
    
    Trie() { root = new TrieNode(); }
    
    void insert(const string& word) {
        TrieNode* cur = root;
        
        for (auto c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
            ++cur->score;
        }
    }
    
    int search(const string& word) {
        TrieNode* cur = root;
        int ans = 0;
        
        for (auto c : word) {
            int idx = c - 'a';
            cur = cur->children[idx];
            if (!cur) break;
            ans += cur->score;
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        struct Node {
            Node *son[26]{};
            int score = 0;
        };
        Node *root = new Node();
        for (auto &word : words) {
            auto cur = root;
            for (char c : word) {
                c -= 'a';
                if (cur->son[c] == nullptr) cur->son[c] = new Node();
                cur = cur->son[c];
                ++cur->score; // 更新所有前缀的分数
            }
        }

        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            auto cur = root;
            for (char c : words[i]) {
                cur = cur->son[c - 'a'];
                ans[i] += cur->score; // 累加分数，即可得到答案
            }
        }
        return ans;

    }
};