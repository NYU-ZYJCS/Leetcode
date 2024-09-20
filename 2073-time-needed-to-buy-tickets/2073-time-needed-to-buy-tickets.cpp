class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // left: min(ticket, k)
        // right: min(ticket, k - 1)
        int res = 0;
        int n = tickets.size();
        for (int i = 0; i < n; ++i) {
            if (i <= k) res += min(tickets[i], tickets[k]);
            else res += min(tickets[i], tickets[k] - 1);
        }
        
        return res;
    }
};