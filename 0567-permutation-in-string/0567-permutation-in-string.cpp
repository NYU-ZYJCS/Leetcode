class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for (auto c : s1) freq[c - 'a']++;
        
        for (int left = 0, right = 0; right < s2.size(); ++right) {
            char c = s2[right];
            --freq[c - 'a'];
            while (freq[c - 'a'] < 0) {
                ++freq[s2[left++] - 'a'];
            }
            if (right - left + 1 == s1.size()) return true;
        }
        return false;
    }
};