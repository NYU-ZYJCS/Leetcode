class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.size(), ans = 0;
        int count = 0;
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        
        for (int i = 0; i < size; ++i) {
            if (vowels.find(s[i]) != vowels.end()) ++count;
            
            if (i < k - 1) continue;
            ans = max(ans, count);
            if (vowels.find(s[i - k + 1]) != vowels.end()) --count;
        }
        
        return ans;
    }
};