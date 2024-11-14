class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
    
        function<bool(int)> check = [&] (int k) {
            int count = 0;
            for (auto q : quantities) {
                count += ceil(q * 1.0 / k);
            }
            return count <= n;
        };
        
        int l = 1, r = 10e5;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};