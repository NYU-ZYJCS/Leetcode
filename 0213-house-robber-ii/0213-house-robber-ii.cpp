class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1) return nums[0];
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
    
    int helper(vector<int>& nums, int start, int end) {
        int pre2 = 0, pre1 = 0;
        int result = 0;
        for (int i = start; i < end; ++i) {
            int cur = max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = cur; 
        }
        return pre1;
    }
};