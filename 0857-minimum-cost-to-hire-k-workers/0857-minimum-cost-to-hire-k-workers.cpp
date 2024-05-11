class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        using PDI = pair<double, int>;
        int n = quality.size();

        vector<PDI> wage_per_quality;
        for (int i = 0; i < n; ++i) {
            wage_per_quality.push_back({(double)wage[i] / quality[i], quality[i]});
        }

        ranges::sort(wage_per_quality);
        priority_queue<int> maxHeap;

        double res = 1e18, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += wage_per_quality[i].second;
            maxHeap.push(wage_per_quality[i].second);
            if (maxHeap.size() > k) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                res = min(res, sum * wage_per_quality[i].first);
            }
        }

        return res;
    }
};