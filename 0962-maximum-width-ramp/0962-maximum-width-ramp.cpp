class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> stk;
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            // decreasing stack
            if (stk.empty() || nums[stk.top()] > nums[i]) stk.push(i);
        }
        
        for (int j = n - 1; j >= res; --j) {
            while (!stk.empty() && nums[stk.top()] <= nums[j]) {
                int pos = stk.top();
                stk.pop();
                res = max(res, j - pos);
            }
        }
        
        return res;
    }
};