class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long score = 0;
        while (k--) {
            auto cur = pq.top();
            pq.pop();
            
            score += cur;
            pq.push(ceil(cur / 3.0));
        }
        
        return score;
    }
};