class Solution {
public:
    long long numberOfSubstrings(string s) {
        int freq[26] { 0 };
        long long result = 0;
        
        for (auto c : s) {
            freq[c - 'a']++;
            result += freq[c - 'a'];
        }
        
        return result;
    }
};