class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        queue<pair<int, int>> q_start, q_end;
        unordered_set<int> seen_start, seen_end;
        
        auto hash = [&](int x, int y) { return n * x + y; };
        
        q_start.push({0, 0}), q_end.push({n - 1, n - 1});
        seen_start.insert(hash(0, 0)), seen_end.insert(hash(n - 1, n - 1));
        int steps = 1;
        
        while (!q_start.empty() && !q_end.empty()) {
            if (q_start.size() > q_end.size()) {
                swap(q_start, q_end);
                swap(seen_start, seen_end);
            }
            
            int size = q_start.size();
            while (size--) {
                auto [x, y] = q_start.front();
                q_start.pop();
                
                for (auto dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        int hashCode = hash(nx, ny);

                        if (seen_end.count(hashCode)) {
                            return steps + 1;
                        }

                        if (!seen_start.count(hashCode)) {
                            seen_start.insert(hashCode);
                            q_start.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};