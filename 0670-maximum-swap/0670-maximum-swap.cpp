class Solution {
public:
    int maximumSwap(int num) {
        // 4342450
        string s = to_string(num);
        int n = s.length();
        int max_idx = n - 1;
        int p = -1, q;
        
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[max_idx]) {
                max_idx = i;
            } else if (s[i] < s[max_idx]) {
                p = i;
                q = max_idx;
            }
        }
        
        if (p == -1) return num;
        swap(s[p], s[q]);
        
        return stoi(s);
    }
};