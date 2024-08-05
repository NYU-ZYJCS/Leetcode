class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int m_val = 0;
        vector<vector<short>> dp(s.size() + 1, vector<short>(s.size() + 1));
        for (int i = 0; i < s.size(); ++i)
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    auto val = dp[i + 1][j + 1] = 1 + dp[i][j];
                    if (val > m_val) m_val = val;
                }
            }
        return m_val;
    }
};