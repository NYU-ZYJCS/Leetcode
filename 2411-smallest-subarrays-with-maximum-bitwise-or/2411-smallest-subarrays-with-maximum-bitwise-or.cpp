class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(32, -1);
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; --i) {
            int cnt = i;
            for (int j = 0; j < 32; ++j) {
                if (nums[i] >> j & 1) v[j] = i;
                if (v[j] != -1) cnt = max(cnt, v[j]);
            }
            ans[i] = cnt - i + 1;
        }
        
        return ans;
    }
};