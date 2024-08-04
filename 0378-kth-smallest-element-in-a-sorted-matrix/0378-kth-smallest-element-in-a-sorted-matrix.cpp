class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 1   5  9 
        // 10 11 13
        // 12 13 15
        
        // custom type
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
        };

        // custom compare
        auto cmp = [](point a, point b) {
            return a.val > b.val;
        };

        priority_queue<point, vector<point>, decltype(cmp)> q;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) q.push({matrix[i][0], i, 0});

        while (!q.empty()) {
            auto [val, x, y] = q.top(); q.pop();
            if (--k == 0) return val;
            if (y < n - 1) q.push({matrix[x][y + 1], x, y + 1});
        }
        
        return -1;
    }
};