class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        
        int maxOr = 0;
        for (auto num : nums) {
            maxOr |= num;
        }
        
        function<int(int, int)> helper = [&](int index, int curOr) -> int {
            if (index == n) return (curOr == maxOr) ? 1 : 0;
            
            int countWith = helper(index + 1, curOr | nums[index]);
            int countWithout = helper(index + 1, curOr);
            
            return countWith + countWithout;
        };
        
        return helper(0, 0);
    }
    
};