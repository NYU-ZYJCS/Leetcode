class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        using pii = pair<int, int>;
        int n = grid.size();
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        
        queue<pii> q;
        int d[n][n];
        memset(d, -1, sizeof d);
        
        // put source point into the queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }
        
        // multi source bfs
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || d[nx][ny] != -1) continue;
                q.emplace(nx, ny);
                d[nx][ny] = d[x][y] + 1;
            }
        }
        
        
        // check function for binary search on solution space
        function<bool(int)> check = [&] (int k) -> bool {
            bool f[n][n];
            memset(f, false, sizeof f);
            queue<pii> q;
            
            q.emplace(0, 0);
            f[0][0] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || f[nx][ny] || d[nx][ny] < k) continue;
                    q.emplace(nx, ny);
                    f[nx][ny] = true;
                }
            }
            
            return f[n - 1][n - 1];
        };
        
       int l = 0, r = min(d[0][0], d[n - 1][n - 1]), mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (check(mid))l = mid;
            else r = mid - 1;
        }
        return l;

    }
};