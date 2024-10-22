class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        // delete the duplicate
        set<int> s(nums.begin(), nums.end());
        vector<int> uniqueNums;
        for (int num : s) uniqueNums.push_back(num);
        
        // find the longest subarray with continuous num
        int max_length = 0;
        int n = uniqueNums.size();
        for (int left = 0, right = 0; right < n; ++right) {
            while (uniqueNums[right] - uniqueNums[left] >= nums.size()) {
                ++left;
            }
            max_length = max(max_length, right - left + 1);
        }
        
        return nums.size() - max_length;
    }
};