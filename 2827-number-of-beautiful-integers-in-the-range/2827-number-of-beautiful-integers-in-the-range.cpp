class Solution {
public:
    int count(int high, int k) {
        string s = to_string(high);
        
        // [][][]
        // n digit, k remainder, 2 * n positive
        int n = s.size(), memo[n][k + 1][2 * n + 1];
        memset(memo, -1, sizeof(memo));
        
        function<int(int, int, int, bool, bool)> helper;
        helper = [&] (int i, int remainder, int diff, bool isLimit, bool isNum) -> int {
            if (i == n) return isNum && remainder == 0 && diff == n;
            if (!isLimit && isNum && memo[i][remainder][diff] != -1) return memo[i][remainder][diff];
            
            int res = 0;
            if (!isNum) {
                res += helper(i + 1, remainder, diff, false, false);
            }
            
            int up = isLimit ? s[i] - '0' : 9;
            for (int d = 1 - isNum; d <= up; ++d) {
                res += helper(i + 1, (remainder * 10 + d) % k, diff + d % 2 * 2 - 1, isLimit && d == up, true);
            }
            
            if (!isLimit && isNum) memo[i][remainder][diff] = res;
            return res;
        };
        return helper(0, 0, n, true, false);
    }
    
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return count(high, k) - count(low - 1, k);
    }
};