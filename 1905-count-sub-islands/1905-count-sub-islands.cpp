class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        
        auto bfs = [&] (int sx, int sy) {
            queue<pair<int, int>> q;
            q.emplace(sx, sy);
            
            grid2[sx][sy] = 0;
            bool check = grid1[sx][sy];
            
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (auto dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx < m && ny < n && min(nx, ny) >= 0 && grid2[nx][ny] != 0) {
                        q.emplace(nx, ny);
                        grid2[nx][ny] = 0;
                        
                        if (grid1[nx][ny] == 0) check = false;
                    }
                    
                }
            }
            
            return check;
        };
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) count += bfs(i, j);
            }
        }
        
        return count;
    }
    
    
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};