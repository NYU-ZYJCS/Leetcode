class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        
        vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
        
        
        int pre1 = -1, pre2 = -1;
        for (int i = 0; i < n; ++i) {
            int cur1 = -1, cur2 = -1;
            
            for (int j = 0; j < k; ++j) {
                if (i == 0) {
                    dp[i][j] = costs[i][j]; 
                } else if (j != pre1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][pre1] + costs[i][j]);
                } else if (j != pre2) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][pre2] + costs[i][j]);
                }
                
                if (cur1 == -1 || dp[i][j] < dp[i][cur1]) {
                    cur2 = cur1;
                    cur1 = j;
                } else if (cur2 == -1 || dp[i][j] < dp[i][cur2]) {
                    cur2 = j;
                }
            }
            pre1 = cur1, pre2 = cur2;
        }
        
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};