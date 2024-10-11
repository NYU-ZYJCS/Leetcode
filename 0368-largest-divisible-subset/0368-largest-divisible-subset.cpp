class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int max_length = 1, max_val = nums[0];
        
        ranges::sort(nums);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            if (dp[i] > max_length) {
                max_length = dp[i];
                max_val = nums[i];
            }
            
        }
        
        if (max_length == 1) return {nums[0]};
        
        vector<int> res;
        for (int i = n - 1; i >= 0 && max_length > 0; --i) {
            if (max_length == dp[i] && max_val % nums[i] == 0) {
                res.push_back(nums[i]);
                max_val = nums[i];
                max_length--;
            }
        }
        
        return res;
    }
};