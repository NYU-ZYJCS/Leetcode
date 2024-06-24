class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1);
        
        int revCnt = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            revCnt += diff[i];
            if ((nums[i] + revCnt) % 2 == 0) {
                if (i + k > n) return -1;
                
                ++res;
                ++revCnt;
                --diff[i + k];
            }
        }
        return res;
    }
};