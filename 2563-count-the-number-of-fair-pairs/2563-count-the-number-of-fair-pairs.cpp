class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int left = 0, right = n - 1;
        ranges::sort(nums);
        
        long long small = count(nums, lower - 1);
        long long big = count(nums, upper);
        return big - small;
    }
    
    long long count(vector<int>& nums, int upper) {
        int n = nums.size();
        int left = 0, right = n - 1;
        long long res = 0;
        
        while (left < right) {
            long long sum = nums[left] + nums[right];
            if (sum <= upper) {
                res += right - left;
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};