class Solution {
public:
    vector<int> partitionLabels(string s) {
        // e:0,8
        // c:1,9
        // b:3,6
        // d:7,7
        
        vector<vector<int>> intervals(26, vector<int>(2, -1));
        for (int i = 0; i < s.size(); ++i) {
            int num = s[i] - 'a';
            if (intervals[num][0] == -1) intervals[num][0] = i;
            intervals[num][1] = i;
        }
        
        ranges::sort(intervals);
        vector<int> result;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 0; i < 26; ++i) {
            if (intervals[i][0] == -1) continue;
            
            if (end == -1) {
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                result.push_back(end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        result.push_back(end - start + 1);
        return result;
    }
};