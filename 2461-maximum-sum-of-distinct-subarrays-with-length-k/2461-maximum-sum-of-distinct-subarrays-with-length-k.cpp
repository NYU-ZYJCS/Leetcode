class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0, cur_sum = 0;
        unordered_set<int> exist;
        
        for (int left = 0, right = 0; right < n; ++right) {
            cur_sum += nums[right];
            
            while (exist.contains(nums[right])) {
                exist.erase(nums[left]);
                cur_sum -= nums[left++];
            }
            
            exist.insert(nums[right]);
            if (right - left + 1 == k) {
                max_sum = max(max_sum, cur_sum);
                exist.erase(nums[left]);
                cur_sum -= nums[left++];
            }
        }
        
        return max_sum;
    }
};