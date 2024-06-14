class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // 1 1 2 2 3 7
        // 1 2 3 4 5 7
        ranges::sort(nums);
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                res += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return res;
    }
};