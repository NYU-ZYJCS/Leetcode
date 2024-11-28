class Solution {
     static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        
        deque<pair<int, int>> q;
        q.emplace_back(0, 0);

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            
             for (auto& [dx, dy] : DIRS) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    int v = grid[nx][ny];
                    if (dis[x][y] + v < dis[nx][ny]) {
                        dis[nx][ny] = dis[x][y] + v;
                        v == 0 ? q.emplace_front(nx, ny) : q.emplace_back(nx, ny);
                    }
                }
            }

        }
        
        return dis[m - 1][n - 1];
    }

};