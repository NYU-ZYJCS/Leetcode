class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> minRow(m, INT_MAX), maxCol(n);
        for (int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (minRow[i] == maxCol[j]) ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};