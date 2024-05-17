class Solution {
public:
    // nums[0] <= nums[mid]
    // left = mid
    
    // nums[0] > nums[mid]
    // right
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[size - 1]) {
                left = mid + 1;
            } else {
                // nums[mid] <= nums[size - 1]
                right = mid;
            }
        }
        
        return nums[left];
    }
};