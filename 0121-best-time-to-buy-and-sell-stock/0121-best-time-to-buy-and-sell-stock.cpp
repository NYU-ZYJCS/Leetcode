class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        for (int i = 0; i < prices.size(); ++i) {
            buy = max(buy, -prices[i]);
            sell = max(sell, buy + prices[i]);
        }
        
        return sell;
    }
};