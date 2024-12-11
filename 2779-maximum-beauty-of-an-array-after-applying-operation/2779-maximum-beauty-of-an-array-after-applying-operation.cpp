class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        
        int res = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > k * 2) {
                ++left;
            }
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};