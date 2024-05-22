class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        
        function<void(int, int)> helper = [&] (int pos, int sum) {
            if (path.size() == k && sum == n) {
                result.push_back(path);
                return;
            }
            
            if (pos > 9 || sum == n || path.size() == k) return;
            
            for (int i = pos; i <= 9; ++i) {
                if (i + sum > n) break;
                path.push_back(i);
                helper(i + 1, sum + i);
                path.pop_back();
            }
        };
        
        helper(1, 0);
        return result;
    }
};