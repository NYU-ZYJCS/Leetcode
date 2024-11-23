class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<array<int, 3>> matrix;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                matrix.push_back({grid[i][j], i, j});
        ranges::sort(matrix);
        
        vector<int> rows(m), cols(n);
        vector<vector<int>> res(m, vector<int>(n));
        for (auto &[v, i, j] : matrix) {
            res[i][j] = max(rows[i], cols[j]) + 1;
            rows[i] = cols[j] = res[i][j];
        }
        return res;
    }
};