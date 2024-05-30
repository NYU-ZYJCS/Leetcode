class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int res = 0, prefix = 0;
        
        for (int k = 0; k < n; ++k) {
            int val = prefix ^ arr[k];
            if (cnt.count(val)) {
                res += cnt[val] * k - total[val];
            }
            cnt[prefix]++;
            total[prefix] += k;
            prefix ^= arr[k];
        }
        return res;
    }
};