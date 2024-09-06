class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0.0, r = 1.0;
        
        while (true) {
            double mid = (l + r) / 2;
            int cnt = 0, i = 0, x = 0, y = 1;
            
            for (int j = 1; j < n; ++j) {
                while ((double)arr[i] / arr[j] < mid) {
                    if (arr[i] * y > arr[j] * x) {
                        x = arr[i];
                        y = arr[j];
                    }
                    ++i;
                }
                cnt += i;
            }
            if (cnt == k) return {x,y};
            else if (cnt < k) l = mid;
            else r = mid;
        }
        return {};
    }
};