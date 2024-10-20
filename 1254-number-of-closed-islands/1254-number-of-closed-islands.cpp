class Solution {
    void dfs(vector<vector<int>> &grid, bool &closed, int x, int y) {
        if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[x].size() - 1) {
            if (grid[x][y] == 0) closed = false;
            return;
        }
        
        if (grid[x][y]) return;
        
        grid[x][y] = 1;
        dfs(grid, closed, x - 1, y);
        dfs(grid, closed, x + 1, y);
        dfs(grid, closed, x, y - 1);
        dfs(grid, closed, x, y + 1);
    }

public:
    int closedIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        if (m < 3 || n < 3) return 0;
        
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) { 
                    bool closed = true;
                    dfs(grid, closed, i, j);
                    ans += closed;
                }
            }
        }
        return ans;
    }
};
