class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int res = INT_MAX;
        deque<int> q;
        for (int i = 0; i <= n; ++i) {
            long curSum = prefix[i];
            while (!q.empty() && curSum - prefix[q.front()] >= k) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            
            while (!q.empty() && prefix[q.back()] >= curSum) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};