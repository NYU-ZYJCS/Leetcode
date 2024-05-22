class Solution {
public:
    // dp[i][j]: s[i..j] is a palindrome
    // backtracking
    // for (int i = 0; i < n; ++i) {
    //      for (int j = 0)

    // 
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        
        
        vector<vector<string>> result;
        vector<string> temp;
        function<void(int)> helper = [&] (int pos) {
            if (pos == n) {
                result.push_back(temp);
                return;
            }
            
            for (int i = pos; i < n; ++i) {
                if (dp[pos][i]) {
                    temp.push_back(s.substr(pos, i - pos + 1));
                    helper(i + 1);
                    temp.pop_back();
                }
            }
        };
        
        helper(0);
        return result;
    }
};