class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int cur = INT_MIN, result = 0;
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        for (auto p : pairs) {
            if (cur < p[0]) {
                ++result;
                cur = p[1];
            }
        }
        
        return result;
    }
};