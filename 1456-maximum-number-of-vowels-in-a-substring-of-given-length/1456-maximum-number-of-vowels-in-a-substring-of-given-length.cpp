class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.size(), ans = 0;
        int count = 0;
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        
        for (int i = 0; i < size; ++i) {
            if (vowels.contains(s[i])) ++count;
            
            if (i < k - 1) continue;
            ans = max(ans, count);
            if (vowels.contains(s[i - k + 1])) --count;
        }
        
        return ans;
    }
};