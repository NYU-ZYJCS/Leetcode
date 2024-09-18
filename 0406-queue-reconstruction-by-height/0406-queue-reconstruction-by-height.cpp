class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // [7, 0], [7, 1], [6, 1], [5, 0], [5, 1], [4, 4]
        ranges::sort(people, [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> res;
        for (auto p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};