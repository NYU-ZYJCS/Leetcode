class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int cnt[1024] = {1};
        cnt[0] = 1;
        int prefix = 0;
        long long result = 0;

        for (auto c : word) {
            prefix ^= 1 << (c - 'a');
            result += cnt[prefix];
            
            for (int j = 1; j < 1024; j <<= 1) {
                result += cnt[prefix ^ j];
            }
            cnt[prefix]++;
        }

        return result;
    }
};