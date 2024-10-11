class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int u = 0, d = matrix.size() - 1;
        int l = 0, r = matrix[0].size() - 1;
        
        while (1) {
            for (int i = l; i <= r; ++i) res.push_back(matrix[u][i]);
            if (++u > d) break;
            
            for (int i = u; i <= d; ++i) res.emplace_back(matrix[i][r]);
            if (--r < l) break;

            for (int i = r; i >= l; --i) res.emplace_back(matrix[d][i]);
            if (--d < u) break;

            for(int i = d; i >= u; --i) res.emplace_back(matrix[i][l]);
            if (++l > r) break;
        }
        
        return res;
    }
};