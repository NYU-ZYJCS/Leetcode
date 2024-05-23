class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        unordered_map<int, int> freq;
        
        function<void(int)> helper = [&] (int pos) {
            ++result;
            if (pos == n) return;
            
            for (int i = pos; i < n; ++i) {
                if (freq[nums[i] + k] == 0 && freq[nums[i] - k] == 0) {
                    freq[nums[i]]++;
                    helper(i + 1);
                    freq[nums[i]]--;
                }
            }
        };
        
        helper(0);
        return result - 1;
    }
};