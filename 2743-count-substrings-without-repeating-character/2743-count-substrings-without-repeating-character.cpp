class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int res = 0;
        int freq[26] {0};
        for (int left = 0, right = 0; right < s.size(); ++right) {
            freq[s[right] - 'a']++;
            
            while (freq[s[right] - 'a'] > 1) {
                --freq[s[left++] - 'a'];
            }
            
            res += right - left + 1;
        }
        
        return res;
    }
};