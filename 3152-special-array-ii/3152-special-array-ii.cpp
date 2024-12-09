class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n);
        
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
        }
        
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = (prefix[r] - prefix[l]) == 0;
        }
        
        return res;
    }
};