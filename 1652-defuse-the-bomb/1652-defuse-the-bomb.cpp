class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) return ans;
        
        vector<int> prefix(n * 2 + 1);
        for (int i = 0; i < n * 2; ++i) {
            prefix[i + 1] = prefix[i] + code[i % n];
        }

        
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                ans[i] = prefix[i + k + 1] - prefix[i + 1];
            } else {
                ans[i] = prefix[i + n] - prefix[i + k + n];
            }
        }
        
        return ans;
    }
};