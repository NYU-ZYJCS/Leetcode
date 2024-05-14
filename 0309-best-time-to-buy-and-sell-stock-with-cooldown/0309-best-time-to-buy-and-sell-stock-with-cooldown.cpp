class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0], sell = 0, cooldown = 0;
        
        
        for (int i = 1; i < n; ++i) {
            int pre_buy = buy;
            int pre_sell = sell;
            int pre_cooldown = cooldown;
            buy = max(pre_buy, pre_sell - prices[i]);
            cooldown = max(pre_cooldown, pre_buy + prices[i]);
            sell = max(pre_sell, pre_cooldown);
        }
        
        return max(cooldown, sell);
    }
};