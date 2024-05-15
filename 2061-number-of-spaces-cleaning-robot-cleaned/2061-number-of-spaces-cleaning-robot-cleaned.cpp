class Solution {
public:
    // 0 0 0 1
    // 0 1 0 1
    // 1 0 0 0
    int numberOfCleanRooms(vector<vector<int>>& room) {
        m = room.size(), n = room[0].size();

        
        dfs(room, 0, 0, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (room[i][j] == 2) ++res;
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& room, int row, int col, int dir_index) {      
        if (visited[row][col][dir_index]) return;
        visited[row][col][dir_index] = true;
        room[row][col] = 2;
        
        pair<int, int> dir = dirs[dir_index];
        int nRow = row + dir.first, nCol = col + dir.second;
        if (nRow < 0 || nRow >= m || nCol < 0 || nCol >= n || room[nRow][nCol] == 1) {
            dfs(room, row, col, (dir_index + 1) % 4);
        } else {
            dfs(room, nRow, nCol, dir_index);
        }
    }
    
private:
    int res = 0;
    int m, n;
    bool visited[301][301][5];
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};