class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (auto num : nums) xorSum ^= num;
        // xorSum
        // 3 ^ 5 =
        // 3 011
        // 5 101
        //   110
        // xorSum =  110
        // -xorSum = 010 => 010
        
        // 1111111
        // 0000001
        int first_digit_different = (xorSum == INT_MIN ? 0 : xorSum & (-xorSum));
        vector<int> result(2);
        for (auto num : nums) {
            if (num & first_digit_different) {
                result[1] ^= num;
            } else {
                result[0] ^= num;
            }
        }
        return result;
    }
};