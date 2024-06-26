class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] = dp[i - 1][j], dp[i][j - 1] + grid[i][j]
        // dp[j] = dp[j - 1], dp[j]
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i - 1][j - 1];
            }
        }
        
        return dp.back();
    }
};