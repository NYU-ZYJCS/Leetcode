class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> tasks(n);
        
        for (int i = 0; i < n; ++i) {
            tasks[i] = {difficulty[i], profit[i]};
        }
        ranges::sort(tasks);
        ranges::sort(worker);
        
        for (int i = 1; i < n; ++i) {
            tasks[i].second = max(tasks[i - 1].second, tasks[i].second);
        }
        
        int maxProfit = 0;
        int tIndex = 0;
        int maxPossibleProfit = 0;

        for (int i = 0; i < worker.size(); ++i) {
            while (tIndex < n && worker[i] >= tasks[tIndex].first) {
                maxPossibleProfit = tasks[tIndex].second;
                tIndex++;
            }
            maxProfit += maxPossibleProfit;
        }

        return maxProfit;
    }
};