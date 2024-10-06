class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_set<char> seen;
        
        for (auto c : s) ++freq[c];
        
        string res;
        for (auto c : s) {
            --freq[c];
            if (seen.contains(c)) continue;
            while (res.size() > 0 && c < res.back() && freq[res.back()]) {
                seen.erase(res.back());
                res.pop_back();
            }
            seen.insert(c);
            res.push_back(c);
        }
        
        return res;
    }
};