class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        string ns = s + s;
        int index = kmp(ns, goal);
        
        return index != -1 ? true : false;
    }
    
    
    int kmp(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> next(n);
        
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && t[i] != t[j]) j = next[j - 1];
            
            if (t[i] == t[j]) ++j;
            next[i] = j;
        }
        
        for (int i = 0, j = 0; i < m; ++i) {
            while (j > 0 && s[i] != t[j]) j = next[j - 1];
            if (s[i] == t[j]) ++j;
            
            if (j == n) return i - n + 1;
        }
        
        
        return -1;
    }
};