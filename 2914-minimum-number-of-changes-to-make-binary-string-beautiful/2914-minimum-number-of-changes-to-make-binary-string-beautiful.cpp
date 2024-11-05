class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        if (n % 2 == 1) return -1;
        
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) res++;
        }
        
        return res;
    }
};