class Solution {
public:
    // 0010
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1, p1 = 0;

        while (p1 <= p2) {
            if (nums[p1] == 0) {
                swap(nums[p0++], nums[p1++]);
            } else if (nums[p1] == 2) {
                swap(nums[p2--], nums[p1]);
            } else {
                p1++;
            }
        }

    }
};