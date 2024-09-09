class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int max_count = 0, res = 0;
        
        for (int left = 0, right = 0; right < s.size(); ++right) {
            char c = s[right];
            max_count = max(max_count, ++freq[c - 'A']);
            
            if (right - left + 1 > max_count + k) {
                --freq[s[left++] - 'A'];
            }
            
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};