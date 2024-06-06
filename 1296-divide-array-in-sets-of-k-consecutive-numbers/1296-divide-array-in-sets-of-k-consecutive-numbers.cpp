class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;

        for (auto num : nums) {
            if (!freq.count(num)) continue;
            for (int i = 0; i < k; ++i) {
                if (!freq.count(num + i)) return false;
                if (--freq[num + i] == 0) {
                    freq.erase(num + i);
                }
            }
        }
        return true;
    }
};