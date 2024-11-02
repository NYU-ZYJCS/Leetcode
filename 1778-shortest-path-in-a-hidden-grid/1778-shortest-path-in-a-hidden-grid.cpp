/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    int findShortestPath(GridMaster &master) {
        int x = 1000, y = 1000, cnt = 0;
        map(master, x, y, 'U');


        queue<pair<int, int>> q;
        q.push({x, y});
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto [cx, cy] = q.front();
                q.pop();
                
                
                for (auto& [d, dxy] : dirs) {
                    int nx = cx + dxy[0], ny = cy + dxy[1];
                    
                    if (g[nx][ny] == 2) return cnt + 1;
                    
                    if (g[nx][ny] == 1) {
                        q.push({nx, ny});
                        g[nx][ny] = -1;
                    }
                }
            }
            
            ++cnt;
        }
        
        
        return -1;
    }
    
    void map(GridMaster &master, int x, int y, char back) {
        g[x][y] = master.isTarget() ? 2 : 1;
        
        for (int i = 0; i < 4; ++i) {
            auto& [d, dxy] = dirs[i];
            int nx = x + dxy[0], ny = y + dxy[1];
            
            if (g[nx][ny] == 0) {
                if (master.canMove(d)) {
                    master.move(d);
                    map(master, nx, ny, dirs[i % 2 ? i - 1 : i + 1].first);
                } else {
                    g[nx][ny] = -1;
                }
            }
        }
        master.move(back);
    }
    
private:
    int g[2000][2000] = {};
    vector<pair<char, array<int, 2>>> dirs{{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};
};