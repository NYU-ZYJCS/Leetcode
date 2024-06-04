class Solution {
public:
    int appendCharacters(string s, string t) {
        int left = 0, right = 0;
        while (left < s.size() && right < t.size()) {
            if (s[left] != t[right]) {
                ++left;
            } else {
                ++left, ++right;
            }
        }
        
        return t.size() - right;
    }
};