class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        ranges::sort(nums);
        
        auto check = [&] (int target) -> bool {
            int n = nums.size(), ans = 0;
            for (int i = 0, j = 1; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= target) j++;
                ans += j - i - 1;
            }
            return ans >= k;
        };
        
        int l = 0, r = 1e6;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
    
    
};