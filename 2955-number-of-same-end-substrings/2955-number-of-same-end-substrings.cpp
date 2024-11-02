class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> prefix(26, vector<int>(n + 1, 0));

        // Fill the frequency array
        for (int i = 0; i < n; i++) prefix[s[i] - 'a'][i + 1]++;

        // Convert the frequency array into a prefix sum array
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j + 1] += prefix[i][j];
            }
        }

        vector<int> results;
        
        for (auto q : queries) {
            int start = q[0], end = q[1];
            int result = 0;
            
            for (int i = 0; i < 26; ++i) {
                int count = prefix[i][end + 1] - prefix[i][start]; 
                result += count * (count + 1) / 2; 
            }
            
            results.push_back(result);
        }
        
        return results;
    }
};