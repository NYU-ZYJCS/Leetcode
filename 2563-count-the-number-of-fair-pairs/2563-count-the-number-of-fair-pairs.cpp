class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        ranges::sort(nums);
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }
    
    long long countPairs(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        long long res = 0;
        
        while (l < r) {
            long long sum = nums[l] + nums[r];
            if (sum > target) {
                --r;
            } else {
                res += r - l;
                ++l;
            }
        }
        
        return res;
    }
};