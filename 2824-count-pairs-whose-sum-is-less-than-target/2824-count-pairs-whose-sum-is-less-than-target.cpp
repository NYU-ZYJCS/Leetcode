class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        ranges::sort(nums);
        int res = 0;
        int left = 0, right = nums.size() - 1;
        
        // -1 1 1 2 3
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                res += right - left;
                left++;
            } else {
                right--;
            }
        }
        
        return res;
    }
};