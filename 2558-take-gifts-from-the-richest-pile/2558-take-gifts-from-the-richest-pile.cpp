class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        
        for (int i = 0; i < k; ++i) {
            int cur = pq.top();
            pq.pop();
            
            pq.push(sqrt(cur));
        }
        
        long long res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        
        return res;
    }
};