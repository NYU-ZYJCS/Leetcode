class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ranges::sort(nums);
        return nums;
    }
};