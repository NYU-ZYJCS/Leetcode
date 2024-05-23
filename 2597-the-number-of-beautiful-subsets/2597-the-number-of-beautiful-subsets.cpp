class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, map<int, int>> groups;
        
        for (int x : nums) groups[x % k][x]++;
        
        int res = 1;
        for (auto& [_, g] : groups) {
            int n = g.size();
            int dp[n + 1];
            auto it = g.begin();
            dp[0] = 1;
            dp[1] = 1 << it++->second;
            
            for (int i = 2; it != g.end(); ++it, ++i) {
                if (it->first - prev(it)->first == k) {
                    dp[i] = dp[i - 1] + dp[i - 2] * ((1 << it->second) - 1);
                } else {
                    dp[i] = dp[i - 1]  << it->second;
                }
            }
            
            res *= dp[n];
        }
        
        return res - 1;
    }
};