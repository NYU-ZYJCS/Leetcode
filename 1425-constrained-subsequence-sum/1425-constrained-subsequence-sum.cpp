class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        
        deque<int> stk;
        stk.push_back(0); 
        
        for (int i = 1; i < n; ++i) {
            while (!stk.empty() && i - stk.front() > k) stk.pop_front();
            
            dp[i] = max(0, dp[stk.front()]) + nums[i];
            while (!stk.empty() && dp[i] >= dp[stk.back()]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};