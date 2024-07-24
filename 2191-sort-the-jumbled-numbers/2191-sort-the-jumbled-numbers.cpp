class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        function<int(int)> _transform = [&] (int num) {
            if (num == 0) return mapping[0];
            int ans = 0;
            int multiply = 1;
            while (num > 0) {
                ans += multiply * mapping[num % 10];
                num /= 10;
                multiply *= 10;
            }
            
            return ans;
        };
        
        // increasing
        stable_sort(nums.begin(), nums.end(), [&] (const int& a, const int& b) {
            return _transform(a) < _transform(b);
        });

        
        return nums;
    }
    
};