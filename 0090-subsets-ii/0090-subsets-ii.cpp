class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> path;
        
        ranges::sort(nums);
        
        function<void(int)> helper = [&] (int pos) {
            result.push_back(path);
            
            for (int i = pos; i < n; ++i) {
                if (i > pos && nums[i] == nums[i - 1]) continue;
                
                path.push_back(nums[i]);
                helper(i + 1);
                path.pop_back();
            }
        };
        
        helper(0);
        return result;
    }
};