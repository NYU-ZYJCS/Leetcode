class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0, b = 0;
        int n = s.size();
        
        for (auto c : s) {
            if (c == 'a') a += 1;
            else b = max(a, b) + 1;
        }
        return n - max(a, b);
    }
};