class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int mask = 1 << n;
        
        vector<int> dp(mask, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < mask; ++i) {
            if (dp[i] == INT_MAX) continue;
            
            for (string s : stickers) {
                int cur = i, len = s.size();
                
                for (int k = 0; k < len; ++k) {
                    char c = s[k];
                    
                    for (int p = 0; p < n; ++p) {
                        if (target[p] == c && ((cur >> p) & 1) == 0) {
                            cur |= (1 << p);
                            break;
                        }
                    }
                }
                
                dp[cur] = min(dp[cur], dp[i] + 1);
            }
        }
        
        return dp[mask - 1] == INT_MAX ? -1 : dp[mask - 1];
    }
};