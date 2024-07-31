class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        
        // dfs(i) = min(dfs(i - 1) + max_h)
        for (int i = 0; i < n; ++i) {
            int max_h = 0, left_w = shelfWidth;
            
            for (int j = i; j >= 0; --j) {
                left_w -= books[j][0];
                if (left_w < 0) break;
                max_h = max(max_h, books[j][1]);
                f[i + 1] = min(f[i + 1], f[j] + max_h);
            }
        }
        
        return f[n];
    }
};