class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char, int>, int> freq;
        int res = -1;
        
        for (int i = 0; i < n; ++i) {
            char pre = s[i];
            int count = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] != pre) break;
                
                if (++freq[{pre, j - i + 1}] >= 3) {
                    res = max(res, j - i + 1);
                }
            }
        }
        
        return res;
    }
};