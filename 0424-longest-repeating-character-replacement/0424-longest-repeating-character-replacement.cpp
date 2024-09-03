class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxCount = 0, res = 0;
        
        for (int left = 0, right = 0; right < s.size(); ++right) {
            char c = s[right];
            maxCount = max(maxCount, ++freq[c - 'A']);
            
            while (right - left + 1 > maxCount + k) {
                --freq[s[left++] - 'A'];
            }
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};