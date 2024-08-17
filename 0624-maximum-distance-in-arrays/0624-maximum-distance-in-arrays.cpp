class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int res = 0;
        int min_val = arrays[0][0], max_val = arrays[0].back();
        for (int i = 1; i < n; i ++) {
            res = max(res, max( abs(max_val - arrays[i][0]), abs(arrays[i].back()-min_val) ) );
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }
        return res;
    }
};