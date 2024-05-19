class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<vector<int>> q;
        visited[0][0] = true;
        q.push({0, 0, 1});
        
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            
            if (t[0] == n - 1 && t[1] == n - 1) return t[2];
            
            for (auto dir : directions) {
                int x = t[0] + dir[0];
                int y = t[1] + dir[1];
                if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0 && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y, t[2] + 1});
                }
            }
        }
        
        return -1;
    }
};