class Solution {
    typedef pair<int, pair<int, int>> PII;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        
        int mx = INT_MIN;
        int start = 0, end = INT_MAX;
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(nums[i][0], make_pair(i, 0)));
            mx = max(mx, nums[i][0]);
        }
        
        while (pq.size() == n) {
            PII cur = pq.top();
            pq.pop();
            
            int val = cur.first, row = cur.second.first, idx = cur.second.second;
            if (mx - val < end - start) start = val, end = mx;
            if (idx + 1 < nums[row].size()) {
                pq.push(make_pair(nums[row][idx + 1], make_pair(row, idx + 1)));
                mx = max(mx, nums[row][idx + 1]);
            }
        }
        
        return {start, end};
    }
};