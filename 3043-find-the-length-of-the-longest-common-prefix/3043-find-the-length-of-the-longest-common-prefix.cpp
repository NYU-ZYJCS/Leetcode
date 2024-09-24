struct TrieNode {
   int isEnd;
   unordered_map<char, TrieNode*> children;
   TrieNode() : isEnd(false) {}
};


class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
       TrieNode* node = root;
       for (auto c : word) {
           if (!node->children.contains(c)) {
               node->children[c] = new TrieNode();
           }
           node = node->children[c];
       }
       node->isEnd = true;
    }
    
    int findLongestPrefix(string word) {
        TrieNode* node = root;
        int len = 0;
        
        for (auto c : word) {
            node = node->children[c];
            if (node == nullptr) break;
            else ++len;
        }
        return len;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (auto num : arr1) trie.insert(to_string(num));
        
        int res = 0;
        for (int num : arr2) {
            int len = trie.findLongestPrefix(to_string(num));
            res = max(res, len);
        }
        
        return res;
    }
};