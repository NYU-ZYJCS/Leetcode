class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, mx = values[0] + 0;
        
        for (int i = 1; i < values.size(); ++i) {
            res = max(res, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }
        
        return res;
    }
};