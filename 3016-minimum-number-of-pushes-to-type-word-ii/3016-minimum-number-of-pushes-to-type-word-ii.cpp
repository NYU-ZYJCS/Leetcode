class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (char c: word) {
            freq[c - 'a']++;
        }
        ranges::sort(freq, greater<int>());

        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += freq[i] * (i / 8 + 1);
        }
        
        return res;
    }
};