class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1), res;
        
        for (int i = 0; i < arr.size(); ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        for (auto q : queries) {
            res.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
        }
        
        return res;
    }
};