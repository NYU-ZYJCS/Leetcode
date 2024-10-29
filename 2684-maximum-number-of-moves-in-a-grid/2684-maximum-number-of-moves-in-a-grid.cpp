class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        vector<int> dirs = {-1, 0, 1};
        int res = 1;
        
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                for (auto dir : dirs) {
                    int ni = i + dir, nj = j - 1;
                    if (ni < 0 || ni >= m) continue;
                    
                    // can not move || not strictly bigger
                    if (dp[ni][nj] == 0 || grid[i][j] <= grid[ni][nj]) continue;
                    dp[i][j] = max(dp[ni][nj] + 1, dp[i][j]);
                }
                res = max(res, dp[i][j]);
            }
        }
        
        return res - 1;
    }
};