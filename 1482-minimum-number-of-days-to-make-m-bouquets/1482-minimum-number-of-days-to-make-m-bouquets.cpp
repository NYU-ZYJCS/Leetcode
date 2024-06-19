class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        function<bool(int)> check = [&] (int limit) {
            int flower = 0;
            int bouquets = 0;
            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] <= limit) {
                    ++flower;
                    if (flower == k) {
                        flower = 0;
                        bouquets++;
                    }
                } else {
                    flower = 0;
                }
            }
            return bouquets >= m;
        };
        
        while (low <= high) {
            int limit = low + (high - low) / 2;
            if (check(limit)) {
                high = limit - 1;
            } else {
                low = limit + 1;
            }
        }
        
        return low;
    }
};