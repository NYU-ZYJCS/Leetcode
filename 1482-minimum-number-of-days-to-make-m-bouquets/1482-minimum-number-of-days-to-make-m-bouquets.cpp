class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        auto canMakeBouquets = [&] (int days) {
            int bouquets = 0, flowers = 0;
            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] <= days) {
                    ++flowers;
                    if (flowers == k) {
                        ++bouquets;
                        flowers = 0; // Reset after making a bouquet
                    }
                } else {
                    flowers = 0; // Reset if the flower cannot be used
                }
            }
            return bouquets >= m;
        };

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(mid)) {
                high = mid; // Look for a smaller feasible value
            } else {
                low = mid + 1; // Increase the limit
            }
        }

        return low;
    }

};