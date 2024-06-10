class Solution {
    
    static constexpr int dirs[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    
    bool check_prime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }


public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        unordered_map<int, int> freqs;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 8; ++k) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    int value = mat[i][j];
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        value = value * 10 + mat[x][y];
                        if (freqs.count(value) || check_prime(value)) {
                            ++freqs[value];
                        }
                        x += dirs[k][0], y += dirs[k][1];
                    }
                }
            }
        }
        
        int res = -1, max_freq = 0;
        for (auto [key, freq] : freqs) {
            if (freq > max_freq) {
                res = key;
                max_freq = freq;
            } else if (freq == max_freq) {
                res = max(res, key);
            }
        }
        return res;
    }
};