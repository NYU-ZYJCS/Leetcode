class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        return isMatch(pattern, 0, s, 0);
    }
    
     bool isMatch(string& p, int i, string& s, int j) {
         if (i == p.size() && j == s.size()) return true;
         if (i == p.size() || j == s.size()) return false;
         
         char c = p[i];
         if (mapping.count(c)) {
             int size = mapping[c].size();
             if (s.substr(j, size) != mapping[c]) return false;
             return isMatch(p, i + 1, s, j + size);
         }
         
         // mapping does not exist
         for (int len = 1; len <= s.size() - j; ++len) {
             string temp = s.substr(j, len);
             if (seen.find(temp) != seen.end()) continue;
             
             seen.insert(temp);
             mapping[c] = temp;
             if (isMatch(p, i + 1, s, j + len)) return true;
             mapping.erase(c);
             seen.erase(temp);
         }
         
         return false;
     }
    
private:
    unordered_map<char, string> mapping;
    unordered_set<string> seen;
};