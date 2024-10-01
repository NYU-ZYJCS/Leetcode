class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k);
        
        for (auto num : arr) {
            int mod = ((num % k) + k) % k;
            freq[mod]++;
        }
        
        if (freq[0] & 1) return false;
        
        for (int i = 1; i <= k / 2; ++i) {
            if (freq[i] != freq[k - i]) return false;
        }
        
        
        return true;
    }
};