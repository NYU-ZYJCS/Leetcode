class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;
        
        int max_unique_number = -1;
        for (auto [key, value] : freq) {
            if (value == 1 && key > max_unique_number) {
                max_unique_number = key;
            }
        }
        
        return max_unique_number;
    }
};