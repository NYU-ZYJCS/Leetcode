class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int hash[101];
        
        for (auto array : arrays) {
            for (int num : array) {
                hash[num]++;
            }
        }
        
        int freq = arrays.size();
        vector<int> result;
        for (int i = 1; i <= 100; ++i) {
            if (hash[i] == freq) result.push_back(i);
        } 
        
        return result;
    }
};