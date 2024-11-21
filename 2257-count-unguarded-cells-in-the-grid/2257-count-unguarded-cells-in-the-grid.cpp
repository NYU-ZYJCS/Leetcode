class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res = 0;
        vector<vector<char>> grid(m, vector<char>(n));
        
        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }

        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }

        for (auto guard : guards) {
            int x = guard[0], y = guard[1];
            for (int i = 0; i < 4; i++) {
                int nx = x +  direction[i][0], ny = y + direction[i][1];
                while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 'G' && grid[nx][ny] != 'W') {
                    grid[nx][ny] = 'I';

                    nx += direction[i][0];
                    ny += direction[i][1];
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 'G' && grid[i][j] != 'W' && grid[i][j] != 'I') res++;

            }
        }

        return res;
    }
    
private:
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};