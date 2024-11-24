class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minn = abs(matrix[0][0]);
        long long res = 0;
        int count = 0;
        
        for (auto& v : matrix) {
            for (int num : v) {
                if (num < 0) {
                    ++count;
                    num = -num;
                }
                
                res += num;
                minn = min(num, minn);
            }
        }
        
        if (count % 2) return res - 2 * minn;
        return res;
    }
};