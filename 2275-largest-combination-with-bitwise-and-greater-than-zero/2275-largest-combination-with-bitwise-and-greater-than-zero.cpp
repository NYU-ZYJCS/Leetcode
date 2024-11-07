class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int longest = 0;
        vector<int> bits(32);
        
        for (int i = 0; i < n; ++i) {
            int num = candidates[i];
            
            for (int j = 0; j < 32; ++j) {
                if (num & (1 << j)) bits[j]++;
            }
        }
        
        for (int i = 0; i < 32; ++i) {
            longest = max(longest, bits[i]);
        }
        
        return longest;
    }
};