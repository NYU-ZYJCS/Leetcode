class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }
        return result;
        
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) return 0;
        
        int rec = grid[x][y];
        
        grid[x][y] = 0;
        int left = dfs(grid, x, y - 1);
        int right = dfs(grid, x, y + 1);
        int up = dfs(grid, x - 1, y);
        int down = dfs(grid, x + 1, y);
        grid[x][y] = rec;
        
        
        return max({left, right, up, down}) + grid[x][y];
    }
    
private:
    int m, n;
};