class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase, decrease;
        int left = 0, res = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];
            
            // store the minimal value
            while (!increase.empty() && num < nums[increase.back()]) {
                increase.pop_back();
            }
            increase.push_back(right);

            // store the maximal value
            while (!decrease.empty() && num > nums[decrease.back()]) {
                decrease.pop_back();
            }
            decrease.push_back(right);
            
            while (nums[decrease.front()] - nums[increase.front()] > limit) {
                if (nums[decrease.front()] == nums[left]) decrease.pop_front();
                if (nums[increase.front()] == nums[left]) increase.pop_front();
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};