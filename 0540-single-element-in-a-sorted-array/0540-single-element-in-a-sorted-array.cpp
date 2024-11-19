class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 0 1 2 3
        // 1 1 2 2
        
        // 0 1 2 3
        // 1 2 2 3
        
        // nums[i] == i / 2 + 1;
        
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid & 1) {
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) left = mid + 1;
                else right = mid - 1;
            } else {
                if (mid + 1 < n && nums[mid] == nums[mid + 1]) left = mid + 2;
                else right = mid - 1;
            }
        }
        
        return nums[left];
    }
};