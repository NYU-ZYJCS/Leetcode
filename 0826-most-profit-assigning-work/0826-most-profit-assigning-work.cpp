class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        ranges::sort(jobs);
        ranges::sort(worker);
        int ans = 0, j = 0, max_profit = 0;
        for (int w : worker) {
            while (j < n && jobs[j].first <= w) {
                max_profit = max(max_profit, jobs[j++].second);
            }
            ans += max_profit;
        }
        return ans;
    }
};