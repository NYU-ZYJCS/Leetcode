class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<int> preMax(n);
        int ans = 0;
        int i, j, s;
        
        sort(events.begin(), events.end());
        preMax[n - 1] = events[n - 1][2];
        for (i = n - 2; i >= 0; --i)
            preMax[i] = max(preMax[i + 1], events[i][2]);
        for (i = 0; i < n; ++i) {
            ans = max(ans, events[i][2]);
            s = upper_bound(events.begin(), events.end(), vector<int>{events[i][1] + 1, 0, 0}) - events.begin();
            if (s < n)
                ans = max(ans, events[i][2] + preMax[s]);
        }
        
        return ans;
    }
};