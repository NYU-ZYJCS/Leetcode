class Solution {
public:
    static constexpr int mod = 1'000'000'007;
    
    int checkRecord(int n) {
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(3)));
        f[0][0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (j == 1 && k == 0) { // A
                        f[i][j][k] = (f[i][j][k] + f[i - 1][0][0]) % mod;
                        f[i][j][k] = (f[i][j][k] + f[i - 1][0][1]) % mod;
                        f[i][j][k] = (f[i][j][k] + f[i - 1][0][2]) % mod;
                    }
                    if (k != 0) { // L
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % mod;
                    }
                    if (k == 0) { // P
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][0]) % mod;
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][1]) % mod;
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][2]) % mod;
                    }
                }
            }
        }
        
        int sum = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                sum = (sum + f[n][j][k]) % mod;
            }
        }
        
        return sum;
    }
};