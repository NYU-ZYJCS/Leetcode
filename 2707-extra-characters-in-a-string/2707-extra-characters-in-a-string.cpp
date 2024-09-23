class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j <= i; ++j) {
                string temp = s.substr(j, i - j + 1);
                if (st.contains(temp)) {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }
        
        return dp.back();
    }
};