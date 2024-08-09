class Solution {
public:
    bool ismagic(array<int, 9> m) {
        int count[16] = {0};
        for (auto n : m)
            if (++count[n] > 1 || n > 9) return false;
        return m[0] + m[1] + m[2] == 15
            && m[3] + m[4] + m[5] == 15
            && m[6] + m[7] + m[8] == 15
            && m[0] + m[3] + m[6] == 15
            && m[1] + m[4] + m[7] == 15
            && m[2] + m[5] + m[8] == 15
            && m[0] + m[4] + m[8] == 15
            && m[2] + m[4] + m[6] == 15;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        int m = grid.size(), n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i <= m - 3; i++)
            for (int j = 0; j <= n - 3; j++) {
                if (grid[i + 1][j + 1] != 5) continue;
                array<int, 9> v;
                int w = 0;
                for (int r = i; r < i + 3; r++)
                    for (int c = j; c < j + 3; c++)
                        v[w++] = grid[r][c];
                res += ismagic(v);
            }

        return res;
    }
};