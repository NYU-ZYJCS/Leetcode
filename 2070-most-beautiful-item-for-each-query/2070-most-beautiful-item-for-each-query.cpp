class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ranges::sort(items);
        int n = items.size();
        for (int i = 1; i < n; ++i) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        
        vector<int> res;
        for (auto q : queries) {
            int idx = upper_bound(items.begin(), items.end(), q,
                              [](int value, const vector<int>& item) {
                                  return value < item[0];
                              }) - items.begin();
            
            if (idx == 0) res.push_back(0);
            else res.push_back(items[idx - 1][1]);
        }
        
        return res;
    }
};