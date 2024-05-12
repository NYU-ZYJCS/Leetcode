class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            // 3, 4, 2
            // 3, 4, 4
            
            // 1, 4, 2
            // 1, 2, 2
            if (nums[i] < nums[i - 1]) {
                if (++count >= 2) return false;
                
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1];
                } else {
                    nums[i - 1] = nums[i]; 
                }
            }
        }
        return true;
    }
};