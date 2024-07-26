class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> D(n, vector<int>(n, INT_MAX));
        
        for (auto &e : edges) {
            D[e[0]][e[1]] = e[2];
            D[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || D[i][k] == INT_MAX || D[k][j] == INT_MAX) {
                        continue;
                    }
                    D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
                }
            }
        }

        int ans;
        int minNum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && D[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= minNum) {
                minNum = cnt;
                ans = i;
            }
        }
        return ans;


    }
};