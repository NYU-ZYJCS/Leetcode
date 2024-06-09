class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainder;
        remainder[0]++;
        int prefix = 0;
        int result = 0;

        // 7, 4, -10
        // 2, 1, 
        for (auto num : nums) {
            prefix = ((prefix + num) % k + k) % k;
            if (remainder.count(prefix)) result += remainder[prefix];
            remainder[prefix]++;
        }

        return result;
    }
};