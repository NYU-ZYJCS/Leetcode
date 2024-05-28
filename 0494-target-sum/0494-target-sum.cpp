class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // x + y = target
        // x + abs(y) = sum
        
        // x = target + sum >> 1;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || ((sum + target) & 1)) return 0;
        
        int t = sum + target >> 1;
        vector<int> dp(t + 1, 0);
        
        dp[0] = 1;
        for (int num : nums) {
            for (int j = t; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp.back();
    }
};