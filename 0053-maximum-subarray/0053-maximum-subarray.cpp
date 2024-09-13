class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        // dp[i] = max(dp[i - 1], 0) + nums[i]
        for (int num : nums) {
            sum = max(sum, 0) + num;
            res = max(res, sum); 
        }
        
        return res;
    }
};