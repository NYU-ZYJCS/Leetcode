class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = -1;
        int n = nums.size();
        int cnt[3001]{};
        
        function<void(int)> helper = [&] (int pos) {
            ++result;
            if (pos == n) return;
            
            for (int i = pos; i < n; ++i) {
                int x = nums[i] + k;
                if (cnt[x - k] == 0 && cnt[x + k] == 0) {
                    ++cnt[x];
                    helper(i + 1);
                    --cnt[x];
                }
            }
        };
        
        helper(0);
        return result;
    }
};