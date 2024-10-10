class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n + 1);

        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        

        auto cmp = [](const int a, const vector<int>& b) {
            return a < b[1];
        };
        
        for (int i = 1; i <= n; ++i) {
            int curStartTime = jobs[i - 1][0];
            int preIndex = upper_bound(jobs.begin(), jobs.begin() + i, curStartTime, cmp) - jobs.begin(); 
            dp[i] = max(dp[i - 1], dp[preIndex] + jobs[i - 1][2]);
        }
        
        return dp.back();
    }
};