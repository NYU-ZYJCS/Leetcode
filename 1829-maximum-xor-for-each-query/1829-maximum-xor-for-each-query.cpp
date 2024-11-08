class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int temp = 0, index = n;
        int comp = (1 << maximumBit) - 1;
        
        vector<int> res(n, 0);
        while (index) {
            temp ^= nums[n - index];
            res[--index] = comp - temp & comp;
        }
        
        return res;
    }
};