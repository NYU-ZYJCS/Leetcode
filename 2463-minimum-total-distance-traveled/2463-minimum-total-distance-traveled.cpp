class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // 机器人和工厂的坐标排序
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        const long long INF = 1e15;
        int n = robot.size(), m = factory.size();
        // g[i][j] 表示 min(f[i][j'])，j' <= j
        long long f[n + 1][m + 1], g[n + 1][m + 1];
        // 初值
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) f[i][j] = g[i][j] = INF;
        f[0][0] = 0;
        for (int j = 0; j <= m; j++) g[0][j] = 0;
        
        // 套转移方程
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                long long d = 0;
                for (int ii = i - 1; ii >= 0 && i - ii <= factory[j - 1][1]; ii--) {
                    d += abs(robot[ii] - factory[j - 1][0]);
                    f[i][j] = min(f[i][j], g[ii][j - 1] + d);
                }
            }
            for (int j = 1; j <= m; j++) g[i][j] = min(g[i][j - 1], f[i][j]);
        }

        return g[n][m];
    }
};

