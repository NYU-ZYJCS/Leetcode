class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += nums[i];
        }
        
        int maxCnt = cnt;
        int n = nums.size();
        for (int i = k; i < n + k - 1; i++) {
            cnt += nums[i % n] - nums[(i - k) % n];
            maxCnt = max(cnt, maxCnt);
        }
        return k - maxCnt;
        
    }
};