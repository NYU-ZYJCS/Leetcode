class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n / 4;
        unordered_map<char, int> freq;
        for (auto c : s) freq[c]++;
        
        int result = INT_MAX;
        for (int left = 0, right = 0; right < n; ++right) {
            freq[s[right]]--;
            while (left < n && freq['Q'] <= target && freq['W'] <= target && freq['E'] <= target && freq['R'] <= target) {
                result = min(result, right - left + 1);
               ++freq[s[left++]];
            }
        }
        
        return result;
    }
};