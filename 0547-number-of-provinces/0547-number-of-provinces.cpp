class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_set<int> seen;
        int res = 0;
        // 1 0 0 1
        // 0 1 1 0
        // 0 1 1 1
        // 1 0 1 1
        
        function<void(int)> dfs = [&] (int city) {
        for (int j = 0; j < n; ++j) {
            if (isConnected[city][j] == 1 && seen.find(j) == seen.end()) {
                    seen.insert(j);
                    dfs(j);
                }
            }
        };

        for (int city = 0; city < n; ++city) {
            if (seen.find(city) == seen.end()) {
                seen.insert(city);
                dfs(city);
                res++;
            }
        }
        
        return res;
    }
};