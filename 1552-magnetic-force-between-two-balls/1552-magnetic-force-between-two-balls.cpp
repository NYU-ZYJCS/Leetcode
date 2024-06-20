class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        ranges::sort(position);
        
        function<bool(int)> check = [&] (int force) {
            int count = 1;
            int pre = position[0];
            for (int i = 1; i < n; ++i) {
                if (position[i] >= pre + force) {
                    count++;
                    pre = position[i];
                    if (count >= m) return true;
                }
            }
            
            return count >= m;
        };
        
        int max_val = *max_element(position.begin(), position.end());
        int min_val = *min_element(position.begin(), position.end());
        
        int left = 0, right = max_val - min_val;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
};