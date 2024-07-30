class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        // dp[c][k] = dp[c - 1][k] * (1 - p) + dp[c - 1][k - 1] * p)
        vector<double> dp(target + 1);
        dp[0] = 1.0;
        for (int i = 0; i < prob.size(); ++i)
            for (int k = min(i + 1, target); k >= 0; --k)
                dp[k] = dp[k] * (1 - prob[i]) + (k ? dp[k - 1] : 0) * prob[i];
        
        return dp[target];
    }
};