class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        
        function<void(int, int)> helper = [&] (int prefix, int pos) {
            res += prefix;
            if (pos == n) return;
            
            for (int i = pos; i < n; ++i) {
                prefix ^= nums[i];
                helper(prefix, i + 1);
                prefix ^= nums[i];
            }
         };
        
        helper(0, 0);
        return res;
    }
    
};