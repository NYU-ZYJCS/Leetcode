class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        for (int j = 0; j < n; ++j) {
            int ones = 0;
            for (int i = 0; i < m; ++i) {
                ones += (grid[i][j] == 1);
            }
            res += max(ones, m - ones) * (1 << (n - j - 1));
        }
        
        return res;
    }
};