class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + img[i][j];
            }
        }
        
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int row1 = max(0, i - 1);
                int row2 = min(i + 1, m - 1);
                int col1 = max(0, j - 1);
                int col2 = min(j + 1, n - 1);
                
                int cnt = (row2 - row1 + 1) * (col2 - col1 + 1);
                int sum = prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] - prefix[row1][col2 + 1] + prefix[row1][col1];
                result[i][j] = sum / cnt;
            }
        }
        return result;
    }
};