class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // traverse 0th row, (m-1)th row
        for (int j = 0; j < n; ++j) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1) return;
        
        grid[r][c] = 1;
        for (auto dir : directions) {
            dfs(grid, r + dir[0], c + dir[1]);
        }
    }
    
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};