class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= k) return 1;
            
            for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; --j) {
                nums[j] |= nums[i];
                if (nums[j] >= k) {
                    res = min(res, i - j + 1);
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};