class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        
        for (int i = 0; i < n; ++i) {
            int maxVal = arr[i];
            for (int j = i; j >= 0 && i - j + 1 <= k; --j) {
                maxVal = max(maxVal, arr[j]);
                dp[i + 1] = max(dp[i + 1], dp[j] + (i - j + 1) * maxVal);
            }
        }
        
        return dp[n];
    }
};