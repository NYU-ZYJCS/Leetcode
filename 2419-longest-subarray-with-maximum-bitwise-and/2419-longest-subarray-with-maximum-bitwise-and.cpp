class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_value = *max_element(nums.begin(), nums.end());
        int res = 1, curLength = 0;
        
        for (int num : nums) {
            if (num < max_value) {
                curLength = 0;
            } else {
                curLength++;
            }
            res = max(res, curLength);
        }
        
        return res;
    }
};