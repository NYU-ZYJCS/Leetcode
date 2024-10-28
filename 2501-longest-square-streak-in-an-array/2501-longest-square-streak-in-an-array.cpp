class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // 2 3 4 6 8 16
        ranges::sort(nums);
        int n = nums.size(), res = -1;
        unordered_map<int, int> dp;
        
        for (int i = 0; i < n; ++i) {
            int pre = sqrt(nums[i]);
            if (pre * pre == nums[i] && dp.contains(pre)) {
                dp[nums[i]] = dp[pre] + 1;
                res = max(res, dp[nums[i]]);
            } else {
                dp[nums[i]] = 1;
            }
        }
        
        return res;
    }
};