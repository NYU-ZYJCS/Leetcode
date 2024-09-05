class Solution {
public:
    
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};