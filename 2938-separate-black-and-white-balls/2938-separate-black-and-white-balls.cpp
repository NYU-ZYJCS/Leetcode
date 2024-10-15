class Solution {
public:
    long long minimumSteps(string s) {
        // 10001
        int n = s.size();
        long long result = 0;
        
        for (int left = 0, right = 0; right < n; ++right) {
            if (s[right] == '0') {
                result += right - left;
                left++;
            }
        }
        
        return result;
    }
};