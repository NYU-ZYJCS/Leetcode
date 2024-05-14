class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> visited(m, vector<int>(n));
                    result = max(result, dfs(grid, visited, i, j));
                }
            }
        }
        return result;
        
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] == 1 || grid[x][y] == 0) return 0;
        
        visited[x][y] = 1;
        int left = dfs(grid, visited, x, y - 1);
        int right = dfs(grid, visited, x, y + 1);
        int up = dfs(grid, visited, x - 1, y);
        int down = dfs(grid, visited, x + 1, y);
        visited[x][y] = 0;
        
        return max({left, right, up, down}) + grid[x][y];
    }
    
private:
    int m, n;
};