class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        
        function<void(int, int)> helper = [&] (int sum, int pos) {
            if (sum == target) {
                res.push_back(temp);
                return;
            }

            // 1 1 2 5 6 7 10
            for (int i = pos; i < n; ++i) {
                if (i > pos && candidates[i] == candidates[i - 1]) continue;
                if (sum + candidates[i] <= target) {
                    temp.push_back(candidates[i]);
                    helper(sum + candidates[i], i + 1);
                    temp.pop_back();
                } else break;

            }
        };
        
        helper(0, 0);

        return res;
    }
};