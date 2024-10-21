class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= i && nums[i] >= nums[j]) --j;
            swap(nums[j], nums[i]);
        }
        
        sort(nums.begin() + i + 1, nums.end());
    }
};