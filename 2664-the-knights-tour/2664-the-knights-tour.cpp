class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> board(m, vector<int>(n, -1));
        dfs(r, c, 0, board);
        return board;
    }
    
    bool dfs(int x, int y, int step, vector<vector<int>> &board) {
        int m = board.size(), n = board[0].size();
        
        if (step == m * n) return true;
        
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != -1) return false;
        
        const int dx[] = {1, 1, -1, -1, -2, -2, 2, 2};
        const int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
        
        board[x][y] = step;
        for (int i = 0; i < 8; ++i) {
            if (dfs(x + dx[i], y + dy[i], step + 1, board)) {
                return true;
            }
        }
        board[x][y] = -1;
        
        return false;
    }
};