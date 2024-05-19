class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 2;
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1) return steps;

                for (auto dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // mark as visited
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};