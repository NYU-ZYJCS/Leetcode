class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int count = 0, res = 0;
        prefix[count]++;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 1) ++count;
            if (prefix.count(count - k)) {
                res += prefix[count - k];
            }
            prefix[count]++;
        }
        return res;
    }
};