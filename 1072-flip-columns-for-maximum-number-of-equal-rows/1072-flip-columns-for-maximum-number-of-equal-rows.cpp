class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freqs;
        int res = INT_MIN, n = matrix[0].size();
        
        for (auto row : matrix) {
            string temp(n, 0);
            for (int i = 0; i < n; ++i) {
                temp[i] = row[i] ^ row[0];
            }
            
            res = max(res, ++freqs[temp]);
        }
        
        return res;
    }
};