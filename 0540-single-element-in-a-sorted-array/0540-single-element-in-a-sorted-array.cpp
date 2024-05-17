class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid & 1) {
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) left = mid + 1;
                else right = mid;
            } else {
                if (mid + 1 < n && nums[mid] == nums[mid + 1]) left = mid + 2;
                else right = mid;
            }
        }
        
        return nums[left];
    }
};