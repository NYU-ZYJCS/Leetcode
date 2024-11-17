class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int pre_increasing = 1;
        
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1] + 1) {
                pre_increasing = 1;
            } else {
                pre_increasing++;
            }
            
            if (i >= k - 1) {
                res.push_back(pre_increasing >= k ? nums[i] : -1);
            }
        }
        
        return res;
    }
};