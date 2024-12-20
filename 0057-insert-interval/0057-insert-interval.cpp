class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        int n = intervals.size();
        if (n == 0) {
            res.push_back(newInterval);
            return res;
        }
        
        int start = newInterval[0], end = newInterval[1];
        
        //  ...
        // ..
        int i = 0;
        while (i < n && intervals[i][1] < start) res.push_back(intervals[i++]);
        
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            ++i;
        }
        
        res.push_back({start, end});
        while (i < n) res.push_back(intervals[i++]);
        return res;
    }
};