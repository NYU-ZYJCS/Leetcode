class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    q.push({heightMap[i][j], i * n + j});
                    heightMap[i][j] = -1;
                }
            }
        }
        
        int ans = 0, maxH = INT_MIN;
        
        while (!q.empty()) {
            auto cur_node = q.top();
            q.pop();
            int h = cur_node.first, x = cur_node.second / n, y = cur_node.second % n;
            if (h > maxH) maxH = h;
            
            for (auto dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && heightMap[nx][ny] != -1) {
                    if (heightMap[nx][ny] < maxH) ans += maxH - heightMap[nx][ny];
                    q.push({heightMap[nx][ny], nx * n + ny});
                    heightMap[nx][ny] = -1;
                }
            }
        }
        return ans;
    }
    
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 
};