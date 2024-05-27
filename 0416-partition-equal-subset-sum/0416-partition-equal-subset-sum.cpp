class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        
        int target = sum >> 1;
        
        // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - w] + v)
        // dp[j] = min(dp[j], dp[j - w] + v)
        
        vector<int> dp(target + 1, false);
        dp[0] = true;
        
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        
        return dp.back();
    }
};