class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;
        
        // check the col
        for (int row = 0; row < m; ++row) {
            dfs(heights, pacific, row, 0);
            dfs(heights, atlantic, row, n - 1);
        }
        
        // check the row
        for (int col = 0; col < n; ++col) {
            dfs(heights, pacific, 0, col);
            dfs(heights, atlantic, m - 1, col);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        
        for (auto dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] &&
               heights[nx][ny] >= heights[x][y]) {
                dfs(heights, visited, nx, ny);
            }
        }
        
    }
    
private:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
};