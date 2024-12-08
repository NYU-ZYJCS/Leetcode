class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = *max_element(ribbons.begin(), ribbons.end());
        
        auto check = [&] (int target) {
            int res = 0;
            for (auto r : ribbons) {
                res += r / target;
            }  
            return res >= k;
        };
        
        
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (check(mid)) {
                left = mid + 1;
                res = max(res, mid);
            } else {
                right = mid - 1;
            }
        }
        
        return res;
    }
};