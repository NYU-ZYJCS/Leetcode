class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int pre_max = 0;
        
        for (int i = 0; i < n; ) {
            int ones = __builtin_popcount(nums[i]);
            int cur_max = 0;
            
            while (i < n && __builtin_popcount(nums[i]) == ones) {
                if (nums[i] < pre_max) return false;
                cur_max = max(cur_max, nums[i++]);
            }
            
            pre_max = cur_max;
        }
        
        return true;
    }
};