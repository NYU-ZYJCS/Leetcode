class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freq(n);
        
        for (auto road : roads) {
            freq[road[0]]++;
            freq[road[1]]++;
        }
        
        ranges::sort(freq);
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += (long long)freq[i] * (i + 1);
        }
        
        return result;
    }
};