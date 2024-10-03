class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num : nums) x = (x + num) % p;
        
        if (x == 0) return 0;
        unordered_map<int, int> idx;
        int y = 0, res = nums.size();
        idx[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            y = (y + nums[i]) % p;
            int pre = (y - x + p) % p;
            if (idx.contains(pre)) {
                res = min(res, i - idx[pre]);
            }
            idx[y] = i;
        }
        
        return res == nums.size() ? -1 : res;
    }
};