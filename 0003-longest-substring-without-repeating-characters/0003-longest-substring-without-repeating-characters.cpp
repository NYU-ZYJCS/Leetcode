class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> exist;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            char c = s[right];
            while (exist.contains(c)) {
                exist.erase(s[left++]);
            }
            exist.insert(c);
            res = max(res, right - left + 1);
        }
        return res;
    }
};