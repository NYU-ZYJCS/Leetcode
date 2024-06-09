class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        vector<long long> suffix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        
        long long result = LONG_MIN;
        for (int i = 0; i < n; ++i) {
            result = max({prefix[i + 1], suffix[i], result});
        }
        
        return result;
    }
};